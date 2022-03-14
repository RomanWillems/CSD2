#pragma once
#include "audioEffect.h"
#include "oscillator.h"
#include "sine.h"
#include "circBuffer.h"

typedef unsigned int uint;

class Chorus : public AudioEffect
{
public:
  Chorus(int size, float delayMs, float feedback);
  ~Chorus();

  float applyEffect(float input) override;

  void msToSamps(float delayMS);


protected:
  Oscillator* osc;
  CircBuffer* circ;

private:

  int numSamples;
  float output;



};
