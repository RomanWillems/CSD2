#pragma once

#include <iostream>
#include "oscillator.h"

class AudioEffect
{
public:
  AudioEffect();
  virtual ~AudioEffect();


  //process the sample
  void processFrame(float& input, float& output);

  float getSample();

  void setDryWet(float newDryWet);
  float linMap(float input, int x1, int x2, float min, float max);


  //Samplerate

protected:
  virtual void applyEffect(float& input, float& output) = 0;

public:
  float delaySamps;
  float samplerate = 44100;

private:
  float lastSample;
  float dryWet;
  float wetDry;



};
