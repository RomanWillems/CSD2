#include <iostream>
#include "synth.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "oscillator.h"

#pragma once

class FM_synth : public Synth {
public:
    FM_synth(double samplerate);
    ~FM_synth();
    
    void resetPhase();
    void setModFreq(double modFreq);
    float getModFreq();
    void setCarPitch(float midiPitch);
    float getCarPitch();
    void setCarFreq(float midiPitch);
    float getCarFreq();
    void setModIndex();
    void setRatio(double ratio);
    float getRatio();
    float calculate() override;

private:
    Oscillator* carrier;
    Oscillator* modulator;
    double carFreq;
    double modFreq;
    double modIndex;
    double ratio;
};