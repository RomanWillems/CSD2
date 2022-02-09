#include "square.h"
#include "math.h"

Square::Square(float frequency, double samplerate) : frequency(frequency),
    samplerate(samplerate), amplitude(1.0), sample(0), phase(0) {
    //constructor
    std::cout << "square - constructor\n";
}

Square::~Square() {
    //destructor
    std::cout << "square - destructor\n";
}

float Square::getSample() {
    return sample;
}

void Square::tick() {
    phase += frequency / samplerate;
    if(phase >= 0.5) {
        sample = -1.0;
    }
    else {
        sample = 0.0;
    }
}

void Square::setFrequency(float frequency) {
    this->frequency = frequency;
}

float Square::getFrequency() {
    return frequency;
}