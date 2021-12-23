#include <iostream>
#include "synth.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "oscillator.h"
#include "ui.h"

#pragma once

class FM_synth : public Synth {
public:
    FM_synth();
    ~FM_synth();

    void resetPhase();
    void setModFreq(double modFreq);
    float getModFreq();
    void setCarWaveForm(std::string waveType, double samplerate);
    void setModWaveForm(std::string waveType, double samplerate);
    void setCarPitch(float midiPitch);
    float getCarPitch();
    void setCarFreq(float freq);
    float getCarFreq();
    void setModDepth(double modDepth);
    float calculate() override;

private:
    Oscillator* carrier;
    Oscillator* modulator;
    double carFreq;
    double modFreq;
    double modDepth;
};
