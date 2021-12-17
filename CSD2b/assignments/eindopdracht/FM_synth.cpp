#include <iostream>
#include "FM_synth.h"
#include "math.h"
#define SAMPLERATE 44100


FM_synth::FM_synth(float midiPitch, double samplerate) 
    : Synth(midiPitch, samplerate)
{
    initOscCar("carrier", "sine");
    initOscMod("modulator", "saw");
}

FM_synth::~FM_synth() {

    delete carrier;
    carrier = nullptr;

    delete modulator;
    modulator = nullptr;

}

void FM_synth::initOscCar(std::string type,std::string waveform) 
{
    midiPitch = midiPitch;
    if(waveform == "sine") {
        carrier = new Sine(mtof(midiPitch), samplerate);
    } else if(waveform == "saw") {
        carrier = new Saw(mtof(midiPitch), samplerate);
    } else if(waveform == "square") {
        carrier = new Square(mtof(midiPitch), samplerate);
    }
}

void FM_synth::initOscMod(std::string type,std::string waveform) 
{
    midiPitch = midiPitch + 10;

    if(waveform == "sine") {
        modulator = new Sine(mtof(midiPitch), samplerate);
    } else if(waveform == "saw") {
        modulator = new Saw(mtof(midiPitch), samplerate);
    } else if (waveform == "square") {
        modulator = new Square(mtof(midiPitch), samplerate);
    }
}

void FM_synth::calculate() {
    carrier->tick();
    modulator->tick();
    // sample = carrier->getSample() * modulator->getSample();
    sample = modulator->getSample() * carrier->getSample();
}

