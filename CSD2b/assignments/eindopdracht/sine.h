#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>

class Sine
{
public:
    //constructor and destructor
    Sine(double frequency, double samplerate);
    ~Sine();

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