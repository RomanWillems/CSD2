#include "audioEffect.h"


AudioEffect::AudioEffect(unsigned int samplerate)
{
  this->samplerate = samplerate;
}

AudioEffect::~AudioEffect()
{
}

void AudioEffect::processFrame(float& input, float& output)
{
  //apply the virtual effect from effect class (tremolo, delay etc..)
  applyEffect(input, output);
  output = input * wetDry + output * dryWet;
  lastSample = output;
  //std::cout << "wetDry = " << dryWet << std::endl;
}

float AudioEffect::getSample()
{
  return lastSample;
}

float AudioEffect::setDelayMS(float newDelayMS)
{
  this->delayMS = newDelayMS;
  delaySamps = newDelayMS * (samplerate / 1000);
  return delaySamps;
}


void AudioEffect::setDryWet(float newDryWet)
{
  this-> dryWet = newDryWet;
  //std::cout << "newDryWet = " << newDryWet << std::endl;
  wetDry = 1.0f - newDryWet;
}
