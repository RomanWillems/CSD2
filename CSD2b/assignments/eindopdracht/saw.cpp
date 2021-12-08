#include "saw.h"
#include "math.h"

//constructor saw

Saw::Saw(double frequency, double samplerate) : frequency(frequency),
    amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
    std::cout << "sine - constructor\n";
}

//destructor sine
Saw::~Saw() {
    std::cout << "sine - destructor\n";
}

double Saw::getSample() {
    return sample;
}

void Saw::tick() {
    phase += frequency / samplerate;

    //calculate a saw wave and wrap the phase
    if(phase > 1) phase -= 1.0;
    sample = phase * 2.0 - 1.0;
    sample *= amplitude; 

}

//getters and setters
void Saw::setFrequency(double frequency)
{
    this->frequency = frequency;
}

double Saw::getFrequency()
{
    return frequency;
}