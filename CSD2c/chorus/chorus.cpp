#include "chorus.h"

Chorus::Chorus(int samplerate, float modDepth, int delayMS, float feedback, float modFrequency) :
  AudioEffect(), modDepth(modDepth), delayMS(delayMS), feedback(feedback), modFrequency(modFrequency)
{

  int numSamples = msToSamps(delayMS);
  this->numSamples = numSamples;

  osc = new Sine(modFrequency, samplerate);
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
  float modSig = ((osc->genNextSample() +1) * 10 * modDepth); //+ is middelpunt
  setDelayMS(modSig * delayMS);


  output = input + modulation;

  circ->write(input + (output * feedback));

  float interpol = circ->read() - circ->readNext();
  modulation = linMap(interpol, 0, 1, circ->read(), circ->readNext());
  // modulation *= modDepth;
  // modulation += 1.0 - modDepth;

}

void Chorus::setDelayMS(float delayMS)
{
  int delaySamps = msToSamps(delayMS);
  circ->setReadIndex(delaySamps);
}
