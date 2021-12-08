#include "sine.h"
#include "math.h"

//constructor sine

Sine::Sine(double frequency, double samplerate) : frequency(frequency),
    amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
    std::cout << "sine - constructor\n";
}

//destructor sine
Sine::~Sine() {
    std::cout << "sine - destructor\n";
}

double Sine::getSample() {
    return sample;
}

void Sine::tick() {
    phase += frequency / samplerate;

    //wrap the phae so it stays in  he interval [0,1]
    if(phase > 1);
    sample = sin(M_PI * 2 * phase) * amplitude;
}

//getters and setters
void Sine::setFrequency(double frequency)
{
    this->frequency = frequency;
}

double Sine::getFrequency()
{
    return frequency;
}