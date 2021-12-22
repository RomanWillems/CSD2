#include <iostream>
#include "synth.h"

#pragma once

class Ring_synth: public Synth {
public:
    Ring_synth();
    ~Ring_synth();
    
    void resetPhase();
    void setModFreq(double modFreq);
    float getModFreq();
    void setCarWaveForm(std::string waveType, double samplerate);
    void setModWaveForm(std::string waveType, double samplerate);
    void setCarPitch(float midiPitch);
    float getCarPitch();
    void setCarFreq(float freq);
    float getCarFreq();
    void setFrequencys();
    float calculate() override;
    

private:
    Oscillator* carrier;
    Oscillator* modulator;
    double modFreq;
    float carFreq;
    double oscFreq;

};