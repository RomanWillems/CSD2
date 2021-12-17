#include "sine.h"
#include "math.h"

//constructors sine
Sine::Sine() : Sine(0, 0) {}

Sine::Sine(double frequency, double samplerate) 
    : Oscillator(frequency, samplerate)
{}

//destructor sine
Sine::~Sine() {}

void Sine::calculate(){
    
    sample = sin(M_PI * 2 * phase) * amplitude;
    //TODO move to baseclass
    sample *= amplitude;

}



