#pragma once

#include <iostream>


class CircBuffer {
public:
    CircBuffer(int size, int numSampsDelay);
    ~CircBuffer();

    void setReadIndex(int numSampsDelay);
    void write(float value);
    float read();
    float readNext();

private:
    int wrap(int head);
    int readH;
    int writeH;
    int size;
    int numSampsDelay;
    float* buffer = nullptr;

};
