#include "saw.h"
#include "math.h"

//constructor saw
Saw::Saw() : Saw(0, 0) {}

Saw::Saw(double frequency, double samplerate) 
    : Oscillator(frequency, samplerate)
{}

//destructor sine
Saw::~Saw() {}

//calculate the saw wave
void Saw::calculate() {
    sample = phase * 2.0 - 1.0;

    //TODO move to baseclass
    sample *= amplitude; 

}
