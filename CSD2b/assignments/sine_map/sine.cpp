#include "sine.h"
#include "math.h"

Sine::Sine(float frequency) {
    //constructor
    std::cout << "sine - constructor\n";

    //initzialize members
    this->frequency = frequency;
    amplitude = 1.0;
    sample = 0;
    phase = 0;
}

Sine::~Sine() {
    //destructor
    std::cout << "sine - destructor\n";
}

float Sine::getSample() {
    return sample;
}

void Sine::tick() {
    phase += frequency / SAMPLERATE;
    sample = sin(M_PI * 2 * phase);
}

void Sine::setFrequency(float frequency) {
    this->frequency = frequency;
}

float Sine::getFrequency() {
    return frequency;
}