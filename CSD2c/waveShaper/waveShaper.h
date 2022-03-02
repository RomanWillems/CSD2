
#pragma once

#include <iostream>
#include "math.h"
#include "bufferDebugger.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "oscillator.h"


class WaveShaper
{
public:
  WaveShaper(int buffersize);
  ~WaveShaper();


  enum waveForm {
    SINE = 0,
    SAW,
    SQUARE
  };

void genWaveShapeOscillator(waveForm wave, float freq);
void generateWave(float sharpness);
void bufferWaveShaper(float input, int x);


float interpolation(float input);
void plot_waveshaper();
float map(float input, int x1, int x2 , float min, float max);

protected:
  int buffersize;
  float* wavetableBuffer;
  Oscillator* oscillator;

};
