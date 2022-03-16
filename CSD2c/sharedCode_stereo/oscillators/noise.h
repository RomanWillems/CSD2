#ifndef _NOISE_H
#define _NOISE_H
#include <iostream>
#include <time.h>
#include "oscillator.h"


class Noise : public Oscillator
{
public:
  //Constructor and destructor
  Noise();
  Noise();
  ~Noise();

private:
  // calculate the next sample according to sine calculation
  void calcNextSample() override;
};

#endif
