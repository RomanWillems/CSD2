#include "chorus.h"

Chorus::Chorus(int size, float delayMS, float feedback) :
  AudioEffect(), size(size), write(0), read(delayMS), feedback(feedback)
{

}
