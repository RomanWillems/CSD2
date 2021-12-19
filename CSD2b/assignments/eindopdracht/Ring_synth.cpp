#include <iostream>
#include "Ring_synth.h"
#include "math.h"
#define SAMPLERATE 44100


Ring_synth::Ring_synth(double samplerate) 
    : Synth(samplerate)
{
    carrier = new Sine(samplerate);
    modulator = new Sine(samplerate);
}

Ring_synth::~Ring_synth() 
{
    delete carrier;
    carrier = nullptr;
    
    delete modulator;
    modulator = nullptr;
}

void Ring_synth::resetPhase() 
{
    carrier->resetPhase();
    modulator->resetPhase();
}

// set frequency's
void Ring_synth::setModFreq(double modFreq) 
{
    this->modFreq = modFreq;
    std::cout << "modFreq" << modFreq << std::endl;

}

float Ring_synth::getModFreq()
{
    return modFreq;
}

void Ring_synth::setCarPitch(float midiPitch) 
{
    this->midiPitch = midiPitch;
    setCarFreq(midiPitch);
}

float Ring_synth::getCarPitch() 
{   
    return midiPitch;
    
}

void Ring_synth::setCarFreq(float carFreq)
{
    this->carFreq = mtof(midiPitch);   
    
}

float Ring_synth::getCarFreq()
{
    return carFreq;
}

float Ring_synth::calculate() {

    carrier->tick(carFreq);
    modulator->tick(modFreq);
    // sample = carrier->getSample() * modulator->getSample();
    sample = (carrier->getSample() * modulator->getSample());
    return sample;

}

