#include "circBuffer.h"
#include <cmath>

CircBuffer::CircBuffer(int size, int numSampsDelay) :
    readH(0), writeH(0)
{
    if(numSampsDelay > size){
        throw ("CircBuffer::CircBuffer exceed size.");
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
  readH = writeH - numSampsDelay + size;
  readH = wrap(readH);
}


//write samples
void CircBuffer::write(float value)
{
    buffer[writeH++] = value;
    writeH = wrap(writeH);
}

//read samples
float CircBuffer::read()
{
    float value = buffer[readH++];
    readH = wrap(readH);
    return value;
}
//read next sample to interpolate
float CircBuffer::readNext()
{
    int readNext = readH + 1;
    float value = buffer[readNext++];
    readH = wrap(readNext);
    return value;
}

//wrap function
int CircBuffer::wrap(int head)
{
    if(head >= size) head -= size;
    return head;
}
