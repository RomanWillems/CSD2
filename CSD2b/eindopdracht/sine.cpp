#include "sine.h"
#include "math.h"


//constructor sine
Sine::Sine(double samplerate) : Oscillator(samplerate) {}

//destructor sine
Sine::~Sine() {}


//calculate the next sample according to sine calculation
void Sine::calculate(){
    sample = sin(M_PI * 2 * phase);
}



