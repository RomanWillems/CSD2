#include "audioEffect.h"

AudioEffect::AudioEffect()
{
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

void AudioEffect::setDryWet(float newDryWet)
{
  this-> dryWet = newDryWet;
  //std::cout << "newDryWet = " << newDryWet << std::endl;
  wetDry = 1.0f - newDryWet;
}

float AudioEffect::msToSamps(float delayMS)
{
  return int((delayMS * (samplerate / 1000.0)) + 0.5);
}
