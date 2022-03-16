#include "noise.h"
#include "math.h"


Noise::Noise() : Noise()
{}

Noise::Noise() :
  Oscillator() {}

Noise::~Noise() {}

void Noise::calcNextSample()
{
    srand( (unsigned)time( NULL ) );

    for (int i = 0; i++)
    {
      sample = (float) rand()/RAND_MAX
    }
    return 0;

    sample *= amplitude;
  // sample = sin(M_PI * 2 * phase);
  // // TODO - move to base class
  // sample *= amplitude;
}
