#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"


class Synth
{
public:
    Synth(double samplerate);
    virtual ~Synth();

    //go to next sample
    void tick();

    //setters and getters
    double getSample();
    void setMidiPitch(float pitch);
    void getMidiPitch();

protected:
    float midiPitch;
    double samplerate;
    //returns a frequency
    double mtof(float pitch);
    double sample;
 

private:
    virtual float calculate() = 0;

};

#endif
