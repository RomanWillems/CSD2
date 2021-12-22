#include "square.h"
#include "math.h"

//constructors square
Square::Square(double samplerate) 
    : Oscillator(samplerate)
{}

//destructor sine
Square::~Square() {}

//calculate the square wave
void Square::calculate(){

    if(phase < 0.5) {
        sample = 1.0;
    } else {
        sample = -1.0;
    }
    //TODO - put in baseclass
    sample *= amplitude;
}

