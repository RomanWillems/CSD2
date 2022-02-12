#pragma once

#include <iostream>
#include "oscillator.h"
#include "audioEffect.h"

class Tremolo : public AudioEffect
{
public:
    Tremolo(float freq, int samplerate, std::string waveForm);
    ~Tremolo();

    //setters and getters
    //set the frequency of the tremolo
    void setModFreq(float freq);
    void setModSignal(float sample);

    float getModSignal(float sample);

private:
    float sample;
    Oscillator* osc;
};
