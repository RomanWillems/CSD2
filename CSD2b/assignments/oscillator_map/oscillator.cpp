#include "oscillator.h"

Oscillator::Oscillator(float freq, float amp) {
    std::cout << "inside oscillator constructor\n";
    this->freq = freq;
    this->amp = amp;
}

Oscillator::~Oscillator() {
    std::cout << "inside oscillator destructor\n";
}

bool Oscillator::setFreq(float freq) {
    if(freq > 0 && freq < 22050) {
        this->freq = freq;
        return true;
    } 
    std::cout << "The frequency value is incorrect " << "please enter a value [0, 22049]\n";
    return false;
}

float Oscillator::getFreq() {
    return freq;
}

void Oscillator::setAmp(float amp) {
    if(amp >= 0 && amp <= 1) {
        this->amp = amp;
    } else {
        std::cout << "The Amplitude value is incorrect " << "please enter a value [0, 1]\n";

    }
}

float Oscillator::getAmp() {
    return amp;
}