#include "audioEffect.h"

//TODO:
//Add setDryWet();
//getSample();
//getParameter(); <- key/value

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
