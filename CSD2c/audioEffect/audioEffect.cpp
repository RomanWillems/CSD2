#include "audioEffect.h"

AudioEffect::AudioEffect()
{
}

AudioEffect::~AudioEffect()
{
}

float AudioEffect::processFrame()
{
    //oscilattor is in range [1-,1]
    //transform to [0,1]
    float modSignal = (osc->genNextSample() + 1.0f) * 0.5f;
    return modSignal;
}
