#include <iostream>
#include "synth.h"
#include "math.h"

Synth::Synth(float midiPitch, double samplerate) : sample(0) 
{
    this->midiPitch = midiPitch;
    this->samplerate = samplerate;

    // setMidiPitch(midiPitch);

}

Synth::~Synth() {}


void Synth::tick() {
    calculate();

}

double Synth::getSample() 
{
    return sample;
}

void Synth::setMidiPitch(float pitch)
{
    midiPitch = pitch;
}



double Synth::mtof(float pitch)
{
    //turn midi notes in to FQ
    return pow(2.0, (float(pitch) - 69.0) / 12.0) * 440.0;
}

