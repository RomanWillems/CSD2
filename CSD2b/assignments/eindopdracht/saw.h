#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>

class Saw
{
public:
    //constructor and destructor
    Saw(double frequency, double samplerate);
    ~Saw();

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