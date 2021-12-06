#ifndef _SINE_H
#define _SINE_H
#include <iostream>

class Sine 
{
public:
    //constuctor and destructor
    Sine(float frequency, double samplerate);
    ~Sine();
    
    //reurnt current sample
    float getSample();
    //go to next sample
    void tick();

    //getters and setters
    void setFrequency(float frequency);
    float getFrequency();

private:
    float amplitude;
    float frequency;
    float phase;
    //contains current sample
    float sample;
    double samplerate;

};

#endif
