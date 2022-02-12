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
    void SetModFreq(float freq);
    void getModSignal(float sample);

private:
    Oscillator* osc;
    float sample;
};
