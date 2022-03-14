#include "circBuffer.h"

CircBuffer::CircBuffer(int size, int numSampsDelay) :
    readH(0), writeH(0)
{
    if(numSampleDelay > size){
        throw ("CircBuffer::CircBuffer exceed size.")
    }

    this -> size = size;
    this -> numSampsDelay = numSampsDelay;

    //initialize buffer array
    buffer = new float[size];

    setReadIndex(numSampsDelay);
}

CircBuffer::~CircBuffer()
{
    delete [] buffer;
    buffer = nullptr;
}

void CircBuffer::setReadIndex(int numSampsDelay)
{
  readH = writeH - numSampleDelay + size;
  readH = wrap(readH)
}

void CircBuffer::write(float Value)
{
    buffer[write++] = value;
    writeH = wrap(writeH);
}

float CircBuffer::read()
{
    float value = buffer[readH++];
    readH = wrap(readH);
    return value;
}

int CircBuffer::wrap(int head)
{
    if(head >= size) head -= size;
    return head;
}

void CircBuffer::setNumSampsDelay(float delayInSamps)
{
  this->numSampsDelay = floor(delayInSamps);
  this->readH = writeH - numSampsDelay + size;
  readH = wrap(readH);
}
