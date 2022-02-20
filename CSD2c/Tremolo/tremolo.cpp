#include "tremolo.h"
#include "sine.h"
#include "saw.h"
#include "square.h"




Tremolo::Tremolo(float freq, int samplerate, int waveFormType) : AudioEffect()
{
  // if(waveForm == "Sine") {
  //   osc = new Sine(freq, samplerate);
  // } else if (waveForm == "Saw") {
  //   osc = new Saw(freq, samplerate);
  // } else if (waveForm == "Square") {
  //   osc = new Square(freq, samplerate);
  // }

  switch (waveFormType) {
    case waveFormType::SINE: {
      osc = new Sine(freq, samplerate);
      break;
    }
    case waveFormType::SAW: {
      osc = new Saw(freq, samplerate);
      break;
    }
    case waveFormType::SQUARE: {
      osc = new Square(freq, samplerate);
      break;
    }
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

void Tremolo::applyEffect(float& input, float& output)
{

  modSignal = (osc->genNextSample() + 1.0f) * 0.5f;
  // modSignal *= modDepth;
  // modSignal += 1.0 - modDepth;

  output = input * modSignal;


}
