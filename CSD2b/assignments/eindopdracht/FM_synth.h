#include <iostream>
#include "synth.h"
#include "sine.h"
#include "saw.h"
#include "square.h"

#pragma once

class FM_synth : public Synth {
public:
    FM_synth(float midiPitch, double samplerate);
    ~FM_synth();
    
    void initOscCar(std::string type,std::string waveform);
    void initOscMod(std::string type,std::string waveform);\
    void setCarFreq(double carFreq);
    void setModFreq(double modFreq);
    void setModDepth(double modIndex);
    void setRatio(double ratio);

private:
    void calculate() override;
    Oscillator* carrier;
    Oscillator* modulator;
    double carFreq;
    double modFreq;
    double modIndex;
    double ratio;
};