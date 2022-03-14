#include "chorus.h"

Chorus::Chorus(int size, float delayMS, float feedback) :
  AudioEffect()
{

  msToSamps(delayMS);

  osc = new Sine(0.2, samplerate);
  circ = new CircBuffer(size, numSamples);
}

Chorus::~Chorus()
{
  delete osc;
  delete circ;
  osc = nullptr;
  circ = nullptr;
}

float Chorus::applyEffect(float input)
{
  float modFrequency = ((osc->genNextSample()+1)*200);
  int mod = (int)modFrequency;

  circ->setReadIndex(mod);
  circ->write(input);

  output = circ->read();
  osc->genNextSample();
  return output;
}

void Chorus::msToSamps(float delayMS)
{
  numSamples = (delayMS * (samplerate / 1000.0) + 0.5);
  circ->setNumSampsDelay(numSamples);
}
