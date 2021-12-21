#include <iostream>
#include "synth.h"
#include "math.h"

Synth::Synth(double samplerate) : sample(0) 
{

    // std::cout << midiPitch << std::endl;
    // setMidiPitch(midiPitch);
}

Synth::~Synth() {}


void Synth::tick() {
    
    sample = calculate();
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
    return 440.0 * pow(2.0 , ((pitch-57.0)/12.0));
}

