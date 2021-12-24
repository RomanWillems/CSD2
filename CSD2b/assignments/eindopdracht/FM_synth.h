#include <iostream>
#include "synth.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "oscillator.h"
#include "ui.h"

#pragma once

//create an FM class with al the functions needed
//--------------------------------------------------------------------------------------------//

class FM_synth : public Synth {
public:
    //constructor, destructor
    FM_synth();
    ~FM_synth();

    //reset the phase
    void resetPhase();

    //setters and getters
    void setModFreq(double modFreq);
    float getModFreq();
    void setCarWaveForm(std::string waveType, double samplerate);
    void setModWaveForm(std::string waveType, double samplerate);
    void setCarPitch(float midiPitch) override;
    float getCarPitch();
    void setCarFreq(float freq);
    float getCarFreq();
    void setModDepth(double modDepth);

    //calculate the modulated sample
    float calculate() override;

private:
    //make a pointer for the carrier and modulator oscillator
    Oscillator* carrier;
    Oscillator* modulator;
    double carFreq;
    double modFreq;
    double modDepth;
};
//--------------------------------------------------------------------------------------------//