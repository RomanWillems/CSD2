#pragma once
#include <iostream>
#include <cmath>
#include "audioEffect.h"
#include "oscillator.h"
#include "sine.h"
#include "circBuffer.h"

typedef unsigned int uint;

class TapeDelay : public AudioEffect
{
public:
  TapeDelay(int samplerate, int delayMS, float feedback, float modFrequency, float drive);
  ~TapeDelay();

  void applyEffect(float& input, float &ouput) override;

  void setDelayMS(float delayMS);


protected:
  Oscillator* osc;
  CircBuffer* circ;
  int numSamples;
  int delayMS;
  float feedback;
  float drive;
  float modulation;

};
