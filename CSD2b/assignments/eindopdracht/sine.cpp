#include "sine.h"
#include "math.h"

//constructor sine
Sine::Sine(double frequency, double samplerate) : Oscillator(frequency, samplerate)

{
    std::cout << "sine - constructor\n";
}

//destructor sine
Sine::~Sine() {
    std::cout << "sine - destructor\n";
}


void Sine::calculate(){
    
    sample = sin(M_PI * 2 * phase) * amplitude;

    //TODO move to baseclass
    sample += amplitude;

}



