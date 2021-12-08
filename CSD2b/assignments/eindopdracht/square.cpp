#include "square.h"
#include "math.h"

//constructor sine
Square::Square(double frequency, double samplerate) : frequency(frequency),
    amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
    std::cout << "sine - constructor\n";
}

//destructor sine
Square::~Square() {
    std::cout << "sine - destructor\n";
}

double Square::getSample() {
    return sample;
}

void Square::tick() {
    phase += frequency / samplerate;

    //wrap the phae 
    //and calculate the square wave
    if(phase > 1) phase -= 1.0;
    if(phase < 0.5) {
        sample = 1.0;
    } else {
        sample = -1.0;
    }
    sample += amplitude;
    
}

//getters and setters
void Square::setFrequency(double frequency)
{
    this->frequency = frequency;
}

double Square::getFrequency()
{
    return frequency;
}