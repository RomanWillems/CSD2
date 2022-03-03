#include "waveShaper.h"



WaveShaper::WaveShaper(int buffersize) : buffersize(buffersize)
{
  wavetableBuffer = new float[buffersize];
}

WaveShaper::~WaveShaper()
{
  delete wavetableBuffer;
}

void WaveShaper::genWaveShapeOscillator(waveForm wave, float freq)
{
  switch(wave){
    case waveForm::SINE:{
      oscillator = new Sine(freq, buffersize);
      break;
    }
    case waveForm::SAW:{
      oscillator = new Saw(freq, buffersize);
      break;
    }
    case waveForm::SQUARE:{
      oscillator = new Square(freq, buffersize);
      break;
    }
  }

  for (int i = 0; i < buffersize; i++){
            wavetableBuffer[i] = oscillator->genNextSample();
        }

        delete oscillator;
        oscillator = nullptr;
}

void WaveShaper::generateWave(float sharpness){
    // reference to Ciska Marc AND Pirkle 2013, "Designing Audio Effect Plug-ins in C++" p. 497
    float normalizeFactor = 1.0f / atan(sharpness);
    for(int i = 0; i < buffersize; i++) {
        float mappedVal = map((float)i, 0, buffersize, -1.0f, 1.0f);
        wavetableBuffer[i] = normalizeFactor * atan(sharpness * mappedVal);
  }
}

void WaveShaper::bufferWaveShaper(float input, int x)
{
  wavetableBuffer[x] = input;
}


float WaveShaper::interpolation(float input)
{
    float index = (input + 1) * (buffersize/2);
    int i = (int) index;
    float indexDecimal = index - float(i);
    // ;
    return map(indexDecimal,0,1, wavetableBuffer[i], wavetableBuffer[i + 1]);
}

float WaveShaper::map(float input, int x1, int x2 , float min, float max)
{
    float value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);
    return value;
}

void WaveShaper::plot_waveshaper()
{
    BufferDebugger::writeToFile(wavetableBuffer, buffersize, "output.csv");
}
