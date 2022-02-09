#pragma once

#include <iostream>
#include "oscillator.h"

class Tremolo
{
public:
    Tremolo(float freq, int samplerate);
    ~Tremolo();

    float processFrame(float sample);

    //setters and getters
    //set the frequency of the tremolo
    void SetModFreq(float freq);

private:
    Oscillator* osc;
    float modSignal;
};
