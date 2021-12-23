#include "square.h"
#include "math.h"

//constructors square
Square::Square(double samplerate) : Oscillator(samplerate)
{}

//destructor square
Square::~Square() {}

//calculate the next sample according to square calculation
void Square::calculate(){

    if(phase < 0.5) {
        sample = 1.0;
    } else {
        sample = -1.0;
    }
  sample *= amplitude;
}

