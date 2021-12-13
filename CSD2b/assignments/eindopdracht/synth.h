#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"


class Synth
{
public:
    Synth(float midiPitch, double samplerate);
    ~Synth();

    //go to next sample
    void tick();

    //setters and getters
    double getSample();
    void setMidiPitch(float pitch);

protected:
    float midiPitch;
    //returns a frequency
    double mtof(float pitch);

    double sample;
    Sine sine;


};

#endif
