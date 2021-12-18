#include <iostream>
#include "FM_synth.h"
#include "math.h"
#define SAMPLERATE 44100


FM_synth::FM_synth(float midiPitch, double samplerate)
    : Synth(midiPitch, samplerate)
{
    initOscCar("carrier", "sine");
    initOscMod("modulator", "sine");
}

FM_synth::~FM_synth() 
{
    delete carrier;
    carrier = nullptr;

    delete modulator;
    modulator = nullptr;
}

void FM_synth::initOscCar(std::string type,std::string waveform) 
{
    if(waveform == "sine") {
        carrier = new Sine(carFreq, samplerate);
    } else if(waveform == "saw") {
        carrier = new Saw(carFreq, samplerate);
    } else if(waveform == "square") {
        carrier = new Square(carFreq, samplerate);
    }
}

void FM_synth::initOscMod(std::string type,std::string waveform) 
{
    if(waveform == "sine") {
        modulator = new Sine(modFreq, samplerate);
    } else if(waveform == "saw") {
        modulator = new Saw(modFreq, samplerate);
    } else if (waveform == "square") {
        modulator = new Square(modFreq, samplerate);
    }
}

// set frequency's
void FM_synth::setModFreq(double modFreq) 
{
  modFreq = 1000;
}

void FM_synth::setCarFreq(double carFreq) 
{
  carFreq = mtof(midiPitch);
}

void FM_synth::setRatio(double ratio) 
{
  ratio = 1.07;
}

void FM_synth::setModIndex(double modIndex) 
{
  modIndex = (ratio * mtof(midiPitch)) * 7;
}

//calculate the nieuw sample
void FM_synth::calculate() {
    carrier->tick();
    modulator->tick();
    sample = carrier->getSample() + (modulator->getSample() * modIndex);
}

