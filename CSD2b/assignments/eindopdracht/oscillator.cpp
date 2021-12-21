#include "oscillator.h"
#include "math.h"

//constructor
Oscillator::Oscillator(double samplerate) :
    samplerate(samplerate), sample(0), phase(0), amplitude(1.0)
{
}

Oscillator::~Oscillator() {}

void Oscillator::resetPhase()
{
    phase = 0;
}


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

double Oscillator::getFrequency()
{
    return frequency;
}

//iets mis met phase, geeft een heel raar getal
//frequency klopt niet
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
