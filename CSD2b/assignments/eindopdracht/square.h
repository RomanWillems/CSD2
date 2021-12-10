#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include "oscillator.h"


class Square : public Oscillator
{
public:
    //constructor and destructor
    Square(double frequency, double samplerate);
    ~Square();

    //return the current sample
    double getSample();
    //go to next sample
    void tick();

    //getters and setters
    void setFrequency(double frequency);
    double getFrequency();

private:
    double frequency;
    double amplitude;
    double phase;
    double sample;
    double samplerate;

};

#endif