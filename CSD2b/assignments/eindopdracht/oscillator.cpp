#include "oscillator.h"
#include "math.h"

//constructor
Oscillator::Oscillator(double frequency, double samplerate) : 
    frequency(frequency), amplitude(1.0), phase(0), 
    sample(0), samplerate(samplerate)
{

}

Oscillator::~Oscillator() {}

void Oscillator::initialize(double samplerate) {
     this->samplerate = samplerate;
}

double Oscillator::getSample() {
    return sample;
}


void Oscillator::tick() {
    phase += getFrequency() / samplerate;

    //wrap
    if (phase > 1) phase -= 1.0;

    //let subclasses calculate next sample

    calculate();
    //add calculate with virutal
}

void Oscillator::setFrequency(double frequency) {

    this->frequency = frequency;
}

double Oscillator::getFrequency() {
    
    return frequency;
}





