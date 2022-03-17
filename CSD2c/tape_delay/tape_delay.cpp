#include "tape_delay.h"


TapeDelay::TapeDelay(int samplerate, int delayMS, float feedback, float modFrequency, float drive) :
  AudioEffect(),delayMS(delayMS), feedback(feedback), drive(drive)
{

  int numSamples = msToSamps(delayMS);
  this->numSamples = numSamples;

  osc = new Sine(modFrequency, samplerate);
  circ = new CircBuffer(samplerate, numSamples);
}

TapeDelay::~TapeDelay()
{
  delete osc;
  delete circ;
  osc = nullptr;
  circ = nullptr;
}

void TapeDelay::applyEffect(float &input, float &output)
{

  //TODO do something with de modSig so that the delayed samples are slightly off
  float modSig = (osc->genNextSample() + 5);

  setDelayMS(delayMS + modSig);

  output = input + modulation;

  input = tanh(input * drive);
  circ->write(input + (output * feedback));

  float interpol = circ->read() - circ->readNext();
  modulation = linMap(interpol, 0, 1, circ->read(), circ->readNext());


}

void TapeDelay::setDelayMS(float delayMS)
{
  int delaySamps = msToSamps(delayMS);
  circ->setReadIndex(delaySamps);
}
