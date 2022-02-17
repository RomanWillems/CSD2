#pragma once
#include "audioEffect.h"

typedef unsigned int uint;

class Delay : public AudioEffect
{
public:
  Delay(int size, int numSamples, float feedback);
  ~Delay();

  void applyEffect(float& input, float& output) override;

  float getDistance();

private:
  int size;
  int numSamples;
  float feedback;
  float* buffer;

  int write;
  int read;

  inline float wrap(int place);

};
