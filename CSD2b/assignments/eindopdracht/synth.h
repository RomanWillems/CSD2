#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"


//create a synth class with all the needed functions
//--------------------------------------------------------------------------------------------//
class Synth {
public:
    //constructor, destructor
    Synth();
    virtual ~Synth();

    //go to next sample
    void tick();

    //setters and getters
    double getSample();
    void setMidiPitch(float pitch);
    void getMidiPitch();
    virtual void setCarPitch(float midiPitch) = 0;

    //get calculate from synth subclasses
    virtual float calculate() = 0;

protected:
    float midiPitch;
    double samplerate;
    //returns a frequency
    double mtof(float pitch);
    double sample;
};
//--------------------------------------------------------------------------------------------//
#endif
