#include "tremolo.h"
#include "sine.h"
#include "saw.h"
#include "square.h"




Tremolo::Tremolo(float freq, int samplerate, std::string waveForm) : AudioEffect()
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

void Tremolo::setModFreq(float freq)
{
    osc->setFrequency(freq);
}

void Tremolo::applyEffect(float input, float output)
{

  modSignal = (osc->genNextSample() + 1.0f) * 0.5f;
  output = input * modSignal;

}
