#include <iostream>
#include "FM_synth.h"
#include "math.h"
#define SAMPLERATE 44100


FM_synth::FM_synth(double samplerate) : Synth(samplerate)
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
  setCarFreq(midiPitch);
}

float FM_synth::getCarPitch() 
{   
  return midiPitch;
    
}

void FM_synth::setCarFreq(float midiPitch)
{
  this->carFreq = mtof(midiPitch);
  // std::cout << "carFreq =" << carFreq << std::endl;
  carrier->setFrequency(carFreq);
}

float FM_synth::getCarFreq()
{
  // carFreq = carrier->getFrequency();
  // std::cout << "carFreq = " << carFreq << std::endl;
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

void FM_synth::setModIndex(double ratio, float carFreq) 
{
    //modIndex = (ratio * mtof(midiPitch)) * ADSR
  modIndex = (ratio * carFreq) * 4;
  // std::cout << "carFreq = " << carFreq << std::endl;

}

//calculate the new sample
float FM_synth::calculate() 
{
  modulator->tick(modFreq); 
  // carrier->setFrequency((modulator->getSample() + carFreq) * 7);  
  carrier->tick(modulator->getSample() + carFreq);
  // std::cout << "carFreq = " << carrier->getFrequency() << std::endl;
  sample = carrier->getSample();
  return sample;
}

