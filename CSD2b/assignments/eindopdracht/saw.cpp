#include "saw.h"
#include "math.h"

//constructor saw

Saw::Saw(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
    std::cout << "sine - constructor\n";
}

//destructor sine
Saw::~Saw() {
    std::cout << "sine - destructor\n";
}

//calculate the saw wave
void Saw::calculate() {
    sample = phase * 2.0 - 1.0;

    //TODO move to baseclass
    sample *= amplitude; 

}
