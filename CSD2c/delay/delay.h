#pragma once
#include "audioEffect.h"

typedef unsigned int uint;

class Delay : public AudioEffect
{
public:
  Delay(int size, float delayMS, float feedback);
  ~Delay();

  void applyEffect(float& input, float& output) override;

  float getDistance();

private:
  int size;
  float* buffer;

  int write;
  int read;
  float feedback;
  float delayMS;

  inline float wrap(int place);

};
