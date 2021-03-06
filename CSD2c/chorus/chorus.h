#pragma once
#include "audioEffect.h"
#include "oscillator.h"
#include "sine.h"
#include "circBuffer.h"

typedef unsigned int uint;

class Chorus : public AudioEffect
{
public:
  Chorus(int samplerate, float modDepth, int delayMS, float feedback, float modFrequency);
  ~Chorus();

  void applyEffect(float& input, float &ouput) override;

  void setDelayMS(float delayMS);


protected:
  Oscillator* osc;
  CircBuffer* circ;
  int numSamples;
  float modDepth;
  int delayMS;
  float feedback;
  float modFrequency;
  float modulation;




};
