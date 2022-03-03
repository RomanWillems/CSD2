#pragma once
#include "audioEffect.h"

class Chorus : public AudioEffect
{
public:
  Chorus(int size, float delayMs, float feedback);
  ~Chorus();

  void applyEffect(float &input, float& output) override;

private:
  int size;
  float* buffer;

  int write;
  int read;
  float feedback;

  inline float wrap(int place);
}
