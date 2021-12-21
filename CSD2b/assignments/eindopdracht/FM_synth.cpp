#include <iostream>
#include "FM_synth.h"
#include "math.h"
#define SAMPLERATE 44100


FM_synth::FM_synth(double samplerate) : Synth(samplerate), modDepth(20)
{
    carrier = new Sine(samplerate);
    modulator = new Sine(samplerate);
}

FM_synth::~FM_synth()
{
    delete carrier;
    carrier = nullptr;

    delete modulator;
    modulator = nullptr;
}

void FM_synth::resetPhase()
{
  carrier->resetPhase();
  modulator->resetPhase();
}

// set frequency's
void FM_synth::setModFreq(double modFreq)
{
  this->modFreq = modFreq;
  modulator->setFrequency(modFreq);

  // std::cout << "modFreq =" << modFreq << std::endl;
}

float FM_synth::getModFreq()
{
  return modFreq;
}

void FM_synth::setCarPitch(float midiPitch)
{
  this->midiPitch = midiPitch;
  setCarFreq(mtof(midiPitch));
}

float FM_synth::getCarPitch()
{
  return midiPitch;

}

void FM_synth::setCarFreq(float freq)
{
  carFreq = freq;
  std::cout << "carFreq =" << carFreq << std::endl;
  carrier->setFrequency(carFreq);
}

float FM_synth::getCarFreq()
{
  return carFreq;
}

//set FM parameters
void FM_synth::setRatio(double ratio)
{
  this->ratio = ratio;
}

float FM_synth::getRatio()
{
  return ratio;
}

void FM_synth::setModDepth(double modDepth)
{
  this->modDepth = modDepth;
}

//calculate the new sample
float FM_synth::calculate()
{

  modulator->tick();
  carrier->setFrequency((modulator->getSample() * modDepth + carFreq));
  carrier->tick();
  sample = carrier->getSample();
  return sample;
}
