#include <iostream>
#include "Ring_synth.h"
#include "math.h"
#define SAMPLERATE 44100


Ring_synth::Ring_synth() : Synth()
{
}

Ring_synth::~Ring_synth()
{
    delete carrier;
    carrier = nullptr;

    delete modulator;
    modulator = nullptr;
}

void Ring_synth::resetPhase()
{
    carrier->resetPhase();
    modulator->resetPhase();
}


//set the waveform
void Ring_synth::setCarWaveForm(std::string waveType, double samplerate)
{
  if(waveType == "sine") {
     carrier = new Sine(samplerate);
  } else if(waveType == "saw") {
     carrier = new Saw(samplerate);
  } else if (waveType == "square") { 
    modulator = new Square(samplerate);
  }
}

void Ring_synth::setModWaveForm(std::string waveType, double samplerate)
{
  if(waveType == "sine") {
     modulator = new Sine(samplerate);
  } else if(waveType == "saw") {
     modulator = new Saw(samplerate);
  } else if (waveType == "square") { 
    modulator = new Square(samplerate);
  }
}

// set frequency's
void Ring_synth::setModFreq(double modFreq)
{
    this->modFreq = modFreq;
    std::cout << "modFreq" << modFreq << std::endl;

}

float Ring_synth::getModFreq()
{
    return modFreq;
}

void Ring_synth::setCarPitch(float midiPitch)
{
    this->midiPitch = midiPitch;
    setCarFreq(mtof(midiPitch));
}

float Ring_synth::getCarPitch()
{
    return midiPitch;

}

void Ring_synth::setCarFreq(float freq)
{
    carFreq = freq;
    carrier->setFrequency(carFreq);

}

float Ring_synth::getCarFreq()
{
    return carFreq;
}

float Ring_synth::calculate() {

    carrier->tick();
    modulator->tick();
    sample = (carrier->getSample() * modulator->getSample());
    return sample;

}
