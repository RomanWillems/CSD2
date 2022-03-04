#pragma once
#include "audioEffect.h"

typedef unsigned int uint;

class Chorus : public AudioEffect
{
public:
  Chorus(int size, float delayMs, float feedback);
  ~Chorus();

  void applyEffect(float &input, float& output) override;

  void msToSamps(float delayMS);

private:
  int size;
  float* buffer;
  int numsamples = 0;

  int write;
  int read;
  float feedback;

  inline float wrap(int place);
};
