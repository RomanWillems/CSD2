#include <iostream>
#include "FM_synth.h"
#include "math.h"
#define SAMPLERATE 44100


FM_synth::FM_synth(double samplerate)
    : Synth(samplerate)
{
    carrier = new Sine(samplerate);
    modulator = new Sine(samplerate);}

FM_synth::~FM_synth() 
{
    delete carrier;
    carrier = nullptr;

    delete modulator;
    modulator = nullptr;
}


// set frequency's
void FM_synth::setModFreq(double modFreq) 
{
  this->modFreq = 100;
}

void FM_synth::setCarPitch(float midiPitch) 
{
  this->carFreq = mtof(midiPitch);
}

void FM_synth::setRatio(double ratio) 
{
  this->ratio = 1.07;
}

void FM_synth::setModIndex() 
{
    //modIndex = (ratio * mtof(midiPitch)) * ADSR
  modIndex = (ratio * carFreq) * 7;
  std::cout << "modIndex =" << modIndex << std::endl;
}

//calculate the nieuw sample
float FM_synth::calculate() 
{
    modulator->tick(modFreq); 
    carrier->tick(carFreq);
    carrier->setFrequency(((modulator->getSample() * modIndex)) + carrier->getSample());
    sample = carrier->getSample();
    return sample;
}

