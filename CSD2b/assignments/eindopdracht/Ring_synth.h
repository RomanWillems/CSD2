#include <iostream>
#include "synth.h"

#pragma once

class Ring_synth: public Synth {
public:
    Ring_synth(float midiPitch, double samplerate);
    ~Ring_synth();
    
    void initOscCar(std::string type,std::string waveform);
    void initOscMod(std::string type,std::string waveform);

private:
    void calculate() override;
    Oscillator* carrier;
    Oscillator* modulator;
};