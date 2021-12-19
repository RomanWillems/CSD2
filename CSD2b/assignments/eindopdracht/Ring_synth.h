#include <iostream>
#include "synth.h"

#pragma once

class Ring_synth: public Synth {
public:
    Ring_synth(double samplerate);
    ~Ring_synth();
    
    void resetPhase();
    void setModFreq(double modFreq);
    float getModFreq();
    void setCarPitch(float midiPitch);
    float getCarPitch();
    void setCarFreq(float midiPitch);
    float getCarFreq();
    void setFrequencys();

    float calculate();
    

private:
    Oscillator* carrier;
    Oscillator* modulator;
    double modFreq;
    float carFreq;
    double oscFreq;

};