#pragma once

#include <iostream>
#include "oscillator.h"

class AudioEffect
{
public:
  AudioEffect();
  ~AudioEffect();

  float processFrame();

private:
  Oscillator* osc;
};
