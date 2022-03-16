#pragma once

#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "circBuffer.h"

class AudioEffect
{
public:
  AudioEffect();
  virtual ~AudioEffect();


  //process the sample
  void processFrame(float& input, float& output);

  float getSample();

  void setDryWet(float newDryWet);


protected:
  virtual void applyEffect(float& input, float& output) = 0;
  float linMap(float input, int x1, int x2, float min, float max);
  int msToSamps(float ms);

public:
  float delaySamps;
  float samplerate = 44100;

private:
  float lastSample;
  float dryWet;
  float wetDry;



};
