#include <iostream>
#include "synth.h"

#pragma once

class AM_synth: public Synth {
public:
    AM_synth(float midiPitch, double samplerate);
    ~AM_synth();
    
    void initOsc(std::string type,std::string waveform);

private:
    void calculate() override;
    Oscillator* carrier;
    Oscillator* modulator;
};