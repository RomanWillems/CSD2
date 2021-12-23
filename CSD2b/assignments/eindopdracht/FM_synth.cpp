#include <iostream>
#include "FM_synth.h"
#include "math.h"
#define SAMPLERATE 44100
#include "ui.h"


FM_synth::FM_synth() : Synth()
{
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

//set the waveform
void FM_synth::setCarWaveForm(std::string waveType, double samplerate)
{
  if(waveType == "sine") {
     carrier = new Sine(samplerate);
  } else if(waveType == "saw") {
     carrier = new Saw(samplerate);
  } else if (waveType == "square") { 
     carrier = new Square(samplerate);
  }
}

void FM_synth::setModWaveForm(std::string waveType, double samplerate)
{
  if(waveType == "sine") {
     modulator = new Sine(samplerate);
  } else if(waveType == "saw") {
     modulator = new Saw(samplerate);
  } else if (waveType == "square") { 
     modulator = new Square(samplerate);
  }
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

//set mod Depth (give in main)
void FM_synth::setModDepth(double modDepth)
{
  this->modDepth = modDepth;
}

//calculate the modulated sample according to FM and give it back
float FM_synth::calculate()
{
  modulator->tick();
  carrier->setFrequency((modulator->getSample() * modDepth + carFreq));
  carrier->tick();
  sample = carrier->getSample();
  return sample;
}
