#include <iostream>
#include "synth.h"

#pragma once

//create an FM class with al the functions needed
//--------------------------------------------------------------------------------------------//
class Ring_synth: public Synth {
public:
    //constructor, destructor
    Ring_synth();
    ~Ring_synth();

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
    void setFrequencys();

    //calculate the modulated sample
    float calculate() override;
    

private:
    //make a pointer for the carrier and modulator oscillator
    Oscillator* carrier;
    Oscillator* modulator;
    double modFreq;
    float carFreq;
    double oscFreq;
};
//--------------------------------------------------------------------------------------------//