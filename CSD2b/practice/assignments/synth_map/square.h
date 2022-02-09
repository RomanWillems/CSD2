#ifndef _SQUARE_H
#define _SQUARE_H
#include <iostream>


class Square
{
public:
    //constuctor and destructor
    Square(float frequency, double samplerate);
    ~Square();

    //getters and setters
    void setFrequency(float frequency);
    float getFrequency();

    //reurnt current sample
    float getSample();
    //go to next sample
    void tick();


private:
    float amplitude;
    float frequency;
    float phase;
    //contains current sample
    float sample;
    double samplerate;

};

#endif
