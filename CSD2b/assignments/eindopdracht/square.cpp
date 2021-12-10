#include "square.h"
#include "math.h"

//constructor sine
Square::Square(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
    std::cout << "sine - constructor\n";
}

//destructor sine
Square::~Square() {
    std::cout << "sine - destructor\n";
}

//calculate the square wave
void Square::calculate(){

    if(phase < 0.5) {
        sample = 1.0;
    } else {
        sample = -1.0;
    }

    //TODO - put in baseclass
    sample += amplitude;
}

