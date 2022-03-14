#include "circBuffer.h"

CircBuffer::CircBuffer(int size, int numSampleDelay) :
    read(0), write(0)
{
    if(numSampleDelay > size){
        throw ("CircBuffer::CircBuffer exceed size.")
    }

    this -> size = size;
    this -> numSampleDelay = numSampleDelay;

    //initialize buffer array
    buffer = new float[size];

    setReadIndex(numSampleDelay);
}

CircBuffer::~CircBuffer()
{
    delete [] buffer;
    buffer = nullptr;
}

void CircBuffer::setReadIndex(int numSampleDelay)
{
  read = write - numSampleDelay + size;
  read = wrap(read)
}

void CircBuffer::write(float Value)
{
    buffer[writeH++] = value;
    writeH = wrapH(writeH);
}

float CircBuffer::read()
{
    float value = buffer[read++];
    read = wrapH(read);
    return value;
}

int circBuffer::wrap()
{
    if(head >= size) head -= size;
    return head;
