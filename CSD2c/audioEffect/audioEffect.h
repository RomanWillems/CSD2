#pragma once

#include <iostream>
#include "oscillator.h"

class AudioEffect
{
public:
  AudioEffect(unsigned int samplerate);
  virtual ~AudioEffect();


  //process the sample
  void processFrame(float& input, float& output);

  float getSample();

  void setDryWet(float newDryWet);
  float setDelayMS(float newDelayMS);

  //Samplerate

protected:
  virtual void applyEffect(float& input, float& output) = 0;


private:
  float lastSample;
  float dryWet;
  float wetDry;
  float delayMS;
  float delaySamps;
  float samplerate;

};
