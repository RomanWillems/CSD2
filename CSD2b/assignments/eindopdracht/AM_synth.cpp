#include <iostream>
#include "AM_synth.h"
#include "math.h"
#define SAMPLERATE 44100


AM_synth::AM_synth(float midiPitch, double samplerate) 
    : Synth(midiPitch, samplerate)
{
    initOsc("carrier", "sine");
    initOsc("modulator", "saw");
}

AM_synth::~AM_synth() {

    delete carrier;
    carrier = nullptr;

    delete modulator;
    modulator = nullptr;

}

void AM_synth::initOsc(std::string type,std::string waveform) 
{
    carrier = new Sine(mtof(midiPitch), samplerate);
    modulator = new Sine(mtof(midiPitch), samplerate);

    if(waveform == "sine") {
        carrier = new Sine(mtof(midiPitch), samplerate);
    } else if(waveform == "saw") {
        carrier = new Saw(mtof(midiPitch), samplerate);
    }

    // osc->initialize(samplerate);

    // if(type == "carrier") {
    //     delete carrier;
    //     carrier = osc1;
    // } else if(type == "modulator") {
    //     delete modulator;
    //     modulator = osc2;
    // }

    
}

void AM_synth::calculate() {
    carrier->tick();
    modulator->tick();
    // sample = carrier->getSample() * modulator->getSample();
    sample = (pow(1.1,modulator->getSample() + carrier->getSample())) - 1;

}

