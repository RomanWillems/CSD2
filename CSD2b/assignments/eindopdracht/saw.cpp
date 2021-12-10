#include "saw.h"
#include "math.h"

//constructor saw

Saw::Saw(double frequency, double samplerate) : Oscillator(frequency, samplerate), 
    frequency(frequency), samplerate(samplerate)
{
    std::cout << "sine - constructor\n";
}

//destructor sine
Saw::~Saw() {
    std::cout << "sine - destructor\n";
}

void Saw::tick() {
    phase += getFrequency() / getSamplerate();

    //calculate a saw wave and wrap the phase
    if(phase > 1) phase -= 1.0;
    sample = phase * 2.0 - 1.0;
    sample *= amplitude; 

}
