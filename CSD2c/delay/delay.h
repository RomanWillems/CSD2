#pragma once
#include "audioEffect.h"

typedef unsigned int uint;

class Delay : public AudioEffect
{
public:
  Delay(int size, float delayMS, float feedback);
  ~Delay();

  void applyEffect(float& input, float& output) override;

  void msToSamps(float delayMS);

  float getDistance();

private:
  int size;
  float* buffer;
  int numsamples;

  int write;
  int read;
  float feedback;

  inline float wrap(int place);

};
