#include <iostream>
#include "synth.h"
#include "sine.h"
#include "saw.h"
#include "square.h"

#pragma once

class FM_synth : public Synth {
public:
    FM_synth(double samplerate);
    ~FM_synth();
    
    void initOscCar(std::string type,std::string waveform);
    void initOscMod(std::string type,std::string waveform);\
    void setCarPitch(float midiPitch);
    void setModFreq(double modFreq);
    void setModIndex();
    void setRatio(double ratio);
    float calculate() override;

private:
    Oscillator* carrier;
    Oscillator* modulator;
    double carFreq;
    double modFreq;
    double modIndex;
    double ratio;
};