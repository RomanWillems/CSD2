#include "oscillator.h"
#include "math.h"

//create the oscillator constructor and destructor
//--------------------------------------------------------------------------------------------//

Oscillator::Oscillator(double samplerate) : 
    samplerate(samplerate), sample(0), phase(0), amplitude(1.0) {}

Oscillator::~Oscillator() {}

//reset Phase
//--------------------------------------------------------------------------------------------//
void Oscillator::resetPhase() 
{
    phase = 0;
}

//initialize samplerate
//--------------------------------------------------------------------------------------------//
void Oscillator::initialize(double samplerate) {
     this->samplerate = samplerate;
}

//set and get frequency
//--------------------------------------------------------------------------------------------//
void Oscillator::setFrequency(double frequency) 
{
    this->frequency = frequency;
}

double Oscillator::getFrequency()
{
    return frequency;
}

//calculate the phase, then calculate the sample with an virtual calculate from the waveform classes.
//And return it
//--------------------------------------------------------------------------------------------//
void Oscillator::tick() 
{
    phase += getFrequency() / samplerate;
    //wrap
    if (phase > 1) phase -= 1.0;
    //let subclasses calculate next sample
    calculate();
    //add calculate with virutal
    // std::cout << "frequency = " << frequency << std::endl;
}

double Oscillator::getSample() {
    return sample;
}