
#pragma once

#include <iostream>
#include "math.h"
#include "bufferDebugger.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "oscillator.h"


class waveShaper
{
public:
  WaveShaper(int bufferzie);
  ~WaveShaper();


  enum waveForm {
    SINE = 0,
    SAW,
    SQUARE,
    SIZE
  };



}
