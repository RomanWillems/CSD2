#include "tremolo.h"
#include "sine.h"



Tremolo::Tremolo(float freq, int samplerate)
{
    osc = new Sine(freq, samplerate);
}

Tremolo::~Tremolo()
{
    delete osc;
    osc = nullptr;
}

void Tremolo::SetModFreq(float freq)
{
    osc->setFrequency(freq);
}

float Tremolo::processFrame(float sample)
{

    //oscilattor is in range [1-,1]
    //ransform to [0,1]
    float modSignal = (osc->genNextSample() + 1.0f) * 0.5f;

    return sample * amplitude;
}
