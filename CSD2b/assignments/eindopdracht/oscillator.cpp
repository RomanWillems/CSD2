#include "oscillator.h"
#include "math.h"

//constructor
Oscillator::Oscillator(double frequency, double samplerate) : 
    frequency(frequency), samplerate(samplerate), 
    sample(0), phase(0), amplitude(1.0)
{
    
}

Oscillator::~Oscillator() {}

void Oscillator::initialize(double samplerate) {
     this->samplerate = samplerate;
}

double Oscillator::getSample() {
    return sample;
}



void Oscillator::setFrequency(double frequency) 
{
    this->frequency = frequency;
}

double Oscillator::getFrequency() {
    return frequency;
}


//iets mis met phase, geeft een heel raar getal
//frequency klopt niet
void Oscillator::tick() 
{
    phase += frequency / samplerate;
    //wrap
    if (phase > 1) phase -= 1.0;
    //let subclasses calculate next sample
    calculate();
    //add calculate with virutal

    std::cout << "phase =" << phase << std::endl;
}

