#include "sine.h"
#include "math.h"

Sine::Sine(double samplerate) 
    : Oscillator(samplerate)
{}

//destructor sine
Sine::~Sine() {}

void Sine::calculate(){

    sample = sin(M_PI * 2 * phase);

}



