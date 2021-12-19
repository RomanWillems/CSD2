#include <iostream>
#include "Ring_synth.h"
#include "math.h"
#define SAMPLERATE 44100


Ring_synth::Ring_synth(float midiPitch, double samplerate) 
    : Synth(midiPitch, samplerate)
{
    initOscCar("carrier", "sine");
    initOscMod("modulator", "sine");
}

Ring_synth::~Ring_synth() 
{
    delete carrier;
    carrier = nullptr;
    
    delete modulator;
    modulator = nullptr;
}


// set frequency's
void Ring_synth::setModFreq(double modFreq) 
{
    this->modFreq = 100;
}

void Ring_synth::setCarPitch(float midiPitch) 
{
    this->carFreq = mtof(midiPitch);
    

}

void Ring_synth::initOscCar(std::string type,std::string waveform) 
{
    if(waveform == "sine") {
        carrier = new Sine(carFreq, samplerate);
    } else if(waveform == "saw") {
        carrier = new Saw(carFreq, samplerate);
    } else if(waveform == "square") {
        carrier = new Square(carFreq, samplerate);
    }
}

void Ring_synth::initOscMod(std::string type,std::string waveform) 
{
    if(waveform == "sine") {
        modulator = new Sine(modFreq, samplerate);
    } else if(waveform == "saw") {
        modulator = new Saw(modFreq, samplerate);
    } else if (waveform == "square") {
        modulator = new Square(modFreq, samplerate);
    }
}

float Ring_synth::calculate() {
    carrier->tick();
    modulator->tick();
    // sample = carrier->getSample() * modulator->getSample();
    sample = (carrier->getSample() * modulator->getSample()) / 2;
    return sample;

}

