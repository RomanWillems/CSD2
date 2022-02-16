#pragma once

#include <iostream>
#include "oscillator.h"
#include "audioEffect.h"

class Tremolo : public AudioEffect
{
public:
    Tremolo(float freq, int samplerate, std::string waveForm);
    ~Tremolo() override;

    //setters and getters
    //set the frequency of the tremolo
    void setModFreq(float freq);
    void applyEffect(float& input, float& output) override;



protected:
    float sample;
    Oscillator* osc;
    float modSignal = 0;
};
