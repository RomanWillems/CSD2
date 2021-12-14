#include <iostream>
#include "FM_synth.h"
#define SAMPLERATE 44100


FM_synth::FM_synth(float midiPitch, double samplerate) 
    : Synth(midiPitch, samplerate)
{
    initOsc("carrier", "sine");
    initOsc("modulator", "saw");
}

FM_synth::~FM_synth() {

    delete carrier;
    carrier = nullptr;

    delete modulator;
    modulator = nullptr;
    
}

void FM_synth::initOsc(std::string type,std::string waveform) 
{
    carrier = new Sine(mtof(midiPitch), samplerate);
    modulator = new Sine(mtof(midiPitch), samplerate);

    if(waveform == "sine") {
        carrier = new Sine(mtof(midiPitch), samplerate);
    } else if(waveform == "saw") {
        carrier = new Sine(mtof(midiPitch), samplerate);
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

void FM_synth::calculate() {
    carrier->tick();
    modulator->tick();
    sample = carrier->getSample() * modulator->getSample();
}

