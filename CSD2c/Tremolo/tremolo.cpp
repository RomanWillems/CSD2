#include "tremolo.h"
#include "sine.h"
#include "saw.h"
#include "square.h"




Tremolo::Tremolo(float freq, int samplerate, std::string waveForm) : modSignal(0)
{
  if(waveForm == "Sine") {
    osc = new Sine(freq, samplerate);
  } else if (waveForm == "Saw") {
    osc = new Saw(freq, samplerate);
  } else if (waveForm == "Square") {
    osc = new Square(freq, samplerate);
  }
}

Tremolo::~Tremolo()
{
    delete osc;
    osc = nullptr;
}

void Tremolo::SetModFreq(float freq)
{
    osc->setFrequency(freq);
}

float Tremolo::processFrame(float sample)
{

    //oscilattor is in range [1-,1]
    //transform to [0,1]
    float modSignal = (osc->genNextSample() + 1.0f) * 0.5f;

    return modSignal;
}
