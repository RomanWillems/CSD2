#include "delay.h"



Delay::Delay(int size, float numSamples, float feedback) : AudioEffect(samplerate),
  size(size), write(0), read(size - numSamples), feedback(feedback)
{
    if(numSamples > size) {
      throw "Samples exceeds delay size";
    }

    buffer = new float[size];
    for(int i = 0; i < size; i++) {
      buffer[i] = 0;
    }
  }

  Delay::~Delay()
  {
    delete [] buffer;
    buffer = nullptr;
  }

  void Delay::applyEffect(float& input, float& output)
  {
    //read value from circular buffer
    output = buffer[read++];
    read = wrap(read);

    //write goes through buffer and writes a sample;
    buffer[write++] = input + (output * feedback);
    write = wrap(write);

  }

  float Delay::getDistance()
  {
    if(write < read) {
      int flip = read;
      flip += size;
      return flip - read;
    }
    return write - read;
  }

  float Delay::wrap(int place)
  {
    if (place >= size) {
      place -= size;
    }
    return place;
  }
