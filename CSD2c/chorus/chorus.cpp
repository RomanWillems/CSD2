#include "chorus.h"

Chorus::Chorus(int samplerate, float feedback) :
  AudioEffect(), feedback(feedback)
{

  int numSamples = msToSamps(delayMS);
  this->numSamples = numSamples;

  osc = new Sine(3, samplerate);
  circ = new CircBuffer(samplerate, numSamples);
}

Chorus::~Chorus()
{
  delete osc;
  delete circ;
  osc = nullptr;
  circ = nullptr;
}

void Chorus::applyEffect(float &input, float &output)
{
  float modFrequency = ((osc->genNextSample()+1)*200);

  circ->setReadIndex(modFrequency);
  circ->write(input + (output * feedback));

  output = input + modulation;

  float interpol = circ->read() - circ->readNext();
  modulation = linMap(interpol, 0, 1, circ->read(), circ->readNext());

}

void Chorus::setDelayMS(float delayMS)
{
  int delaySamps = msToSamps(delayMS);
  circ->setReadIndex(delaySamps);
}
