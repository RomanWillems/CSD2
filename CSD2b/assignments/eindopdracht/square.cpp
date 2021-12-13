#include "square.h"
#include "math.h"

//constructors square
Square::Square() : Square(0, 0) {}

Square::Square(double frequency, double samplerate) 
    : Oscillator(frequency, samplerate)
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
    sample += amplitude;
}

