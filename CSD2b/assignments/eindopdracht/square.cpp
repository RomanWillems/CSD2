#include "square.h"
#include "math.h"

//constructor sine
Square::Square(double frequency, double samplerate) : Oscillator(frequency, samplerate), 
    frequency(frequency), samplerate(samplerate)
{
    std::cout << "sine - constructor\n";
}

//destructor sine
Square::~Square() {
    std::cout << "sine - destructor\n";
}

void Square::tick() {
    phase += getFrequency() / getSamplerate();

    //wrap the phae 
    //and calculate the square wave
    if(phase > 1) {
        phase -= 1.0;
    }

    if(phase < 0.5) {
        sample = 1.0;
    } else {
        sample = -1.0;
    }
    sample += amplitude;
    
}

