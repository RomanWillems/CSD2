#include "synth.h"

Synth::Synth(double samplerate, float midiPitch) : sample(0) {

    //TODO- add to constructor
    setMidiPitch(60)

}

Synth::~Synth() {}

void Synth::tick() {

}

double Synth::getSample() 
{
    return sample;
}

void Synth::setMidiPitch(float pitch)
{
    midiPitch = pitch;
    double freq = mtof(midiPitch);
}

double Synth::mtof(float pitch)
{
    // TODO - implement mtof functionallity
    return 440;
}

