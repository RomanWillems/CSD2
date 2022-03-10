#pragma once
#include "audioEffect.h"
#include "oscillator.h"

typedef unsigned int uint;

class Chorus : public AudioEffect
{
public:
  Chorus(int size, float delayMs, float feedback);
  ~Chorus();

  void applyEffect(float &input, float& output) override;

  void msToSamps(float delayMS);

protected:
  Oscillator* osc;

private:
  float modDepth = 0.5;
  int size;
  float* buffer;
  int numsamples = 0;
  float offset = 0;
  float delayTimeSamples;
  float modSignal;
  float read_mod;
  int readNext;
  float read_dec;


  int write;
  int read;
  float feedback;

  inline float wrap(int place);
};
