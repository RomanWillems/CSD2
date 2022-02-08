#include "circBuffer.h"

CircBuffer::CircBuffer(int size, int numSampleDelay) :
    size(size), numSampleDelay(numSampleDelay) 
{
    if(numSampleDelay > size){
        throw ("CircBuffer::CircBuffer exceed size.")
    }

    //initialize buffer array
    buffer = new float[size];
    // initialize array with 0
    for(int i = 0; i < size; i++) {
        buffer[i] = 0;
    }
}

CircBuffer::~CircBuffer() 
{
    delete [] buffer;
}

CircBuffer::write(float Value) 
{
    buffer[writeH++] = value;
    writeH = wrapH(writeH);
}

CircBuffer::read()
{
    float value = buffer[read++];
    readH = wrapH(readH);
    return value;
}

int circBuffer::wrap()
{
    if(head >= size) head -= size;
    return head;

int CircBuffer::getDistanceRW();
{
    if(writeH < readH) {

    }
}