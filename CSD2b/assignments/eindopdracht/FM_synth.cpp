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


// set frequency's
void FM_synth::setModFreq(double modFreq) 
{
  this->modFreq = 100;
}

void FM_synth::setCarPitch(float midiPitch) 
{
  this->carFreq = mtof(midiPitch);
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

void FM_synth::setRatio(double ratio) 
{
  this->ratio = 1.07;
}

void FM_synth::setModIndex() 
{
    //modIndex = (ratio * mtof(midiPitch)) * ADSR
  modIndex = (ratio * carFreq) * 7;
  std::cout << "modIndex =" << modIndex << std::endl;
}

//calculate the nieuw sample
float FM_synth::calculate() 
{
    modulator->tick(); 
    carrier->tick();
    carrier->setFrequency(((modulator->getSample() * modIndex)) + carrier->getSample());
    sample = carrier->getSample();
    return sample;
}

