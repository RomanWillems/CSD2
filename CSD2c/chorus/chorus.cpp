#include "chorus.h"

Chorus::Chorus(int size, float delayMS, float feedback) :
  AudioEffect(), size(size), feedback(feedback)
{

  msToSamps(delayMS);

  osc = new Sine(0.2, samplerate);

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

  modSignal = (osc->genNextSample() + 1 * 0.5) * modDepth;
  delayTimeSamples = modSignal + offset;
  read_mod = write - delayTimeSamples;
  read = read_mod;
  readNext = readNext + 1;

  read_dec = read_mod - read;

  read = wrap(read);
  readNext = wrap(readNext);

  //read value from circular buffer
  output = linMap(read_dec, 0, 1, buffer[read], buffer[readNext]);

  //write goes through buffer and writes a sample;
  buffer[write++] = input + (output * feedback);
  wrap(write);

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
