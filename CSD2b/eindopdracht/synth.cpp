#include <iostream>
#include "synth.h"
#include "math.h"



//synth constructor, destructor
//--------------------------------------------------------------------------------------------//
Synth::Synth() : sample(0) {}

Synth::~Synth() {}

//get the sample
//--------------------------------------------------------------------------------------------//
void Synth::tick() {
    
    sample = calculate();
}

double Synth::getSample() 
{
    return sample;
}

//set the midiPitch
//--------------------------------------------------------------------------------------------//
void Synth::setMidiPitch(float pitch)
{
    this->midiPitch = pitch;
    setCarPitch(midiPitch);
}

//calculate frequency according to the midiPitch given
//https://newt.phys.unsw.edu.au/jw/notes.html
//--------------------------------------------------------------------------------------------//
double Synth::mtof(float pitch)
{
    //turn midi notes in to FQ
    return 440.0 * pow(2.0 , ((pitch-57.0)/12.0));
}

