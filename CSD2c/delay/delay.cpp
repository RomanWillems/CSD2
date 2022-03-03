#include "delay.h"



Delay::Delay(int size, float delayMS, float feedback) : AudioEffect(),
  size(size), numsamples(0), write(0), read(size - numsamples), feedback(feedback)
{
    if(numsamples > size) {
      throw "Samples exceeds delay size";
    }

    msToSamps(delayMS);

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

  void Delay::msToSamps(float delayMS)
  {
    this->numsamples = int((delayMS * (samplerate / 1000.0)) + 0.5);
    this->read = write - numsamples + size;
    read = wrap(read);

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
