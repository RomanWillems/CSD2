#include "oscillator.h"
#include "math.h"

//constructor
Oscillator::Oscillator(double frequency, double samplerate) : frequency(frequency),
    amplitude(1.0), phase(), sample(0), samplerate(samplerate)
{
    std::cout << "oscillator - constructor\n";
}

Oscillator::~Oscillator() {

    std::cout << "oscillator - destructor";
}

double Oscillator::getSample() {
    return sample;
}


void Oscillator::tick() {
    phase += getFrequency() / getSamplerate();

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

void Oscillator::setSamplerate(double samplerate) {

    this->samplerate = samplerate;
}

double Oscillator::getSamplerate() {

    return samplerate;
}




