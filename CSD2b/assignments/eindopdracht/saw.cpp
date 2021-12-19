#include "saw.h"
#include "math.h"

//constructor saw
Saw::Saw(double samplerate) 
    : Oscillator(samplerate)
{}

//destructor sine
Saw::~Saw() {}

//calculate the saw wave
void Saw::calculate() {
    sample = phase * 2.0 - 1.0;

    //TODO move to baseclass
    sample *= amplitude; 

}
