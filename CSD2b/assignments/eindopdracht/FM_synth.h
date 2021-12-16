#include <iostream>
#include "synth.h"

#pragma once

class FM_synth : public Synth {
public:
    FM_synth(float midiPitch, double samplerate);
    ~FM_synth();
    
    void initOscCar(std::string type,std::string waveform);
    void initOscMod(std::string type,std::string waveform);

private:
    void calculate() override;
    Oscillator* carrier;
    Oscillator* modulator;
};