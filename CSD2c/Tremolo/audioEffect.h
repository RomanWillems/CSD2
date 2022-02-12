#pragma once

#include <iostream>
#include "oscillator.h"

class AudioEffect
{
public:
  AudioEffect();
  ~AudioEffect();

  float processFrame(float sample);

private:
  Oscillator* osc;
};
