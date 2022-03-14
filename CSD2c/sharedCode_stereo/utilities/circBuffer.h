#pragma once

#include <iostream>


class CircBuffer {
public:
    CircBuffer(int size, int numSampleDelay);
    ~CircBuffer();

    void setReadIndex(int numSampsDelay);
    void write(float value);
    float read();

private:
    int wrap();
    int getDistanceRW();
    int readH = size - numSamplesDelay;
    int writeH = 0;
    int size;
    int numSampsDelay;
    float* buffer[4] = {0,0,0,0};

};
