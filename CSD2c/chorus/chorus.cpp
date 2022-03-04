#include "chorus.h"

Chorus::Chorus(int size, float delayMS, float feedback) :
  AudioEffect(), size(size), write(0), read(size - numsamples), feedback(feedback)
{

  msToSamps(delayMS);

  buffer = new float[size];
  for(int i = 0; i < size; i++) {
    buffer[i] = 0;
  }
}

Chorus::~Chorus()
{
  delete [] buffer;
  buffer = nullptr;
}

void Chorus::applyEffect(float& input, float& output)
{
  //read value from circular buffer
  output = buffer[read++];
  read = wrap(read);

  //write goes through buffer and writes a sample;
  buffer[write++] = input + (output * feedback);
  write = wrap(write);

}

void Chorus::msToSamps(float delayMS)
{
  this->numsamples = int((delayMS * (samplerate / 1000.0)) + 0.5);
  this->read = write - numsamples + size;
  read = wrap(read);
}

float Chorus::wrap(int place)
{
  if (place >= size) {
    place -= size;
  }
  return place;
}
