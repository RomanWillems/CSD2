#pragma once

#include <iostream>
#include "oscillator.h"
#include "audioEffect.h"

class Tremolo : public AudioEffect
{
public:
    enum waveFormType {
      SINE,
      SAW,
      SQUARE,
      SIZE
    };
    Tremolo(float freq, int samplerate, int waveFormType);
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
