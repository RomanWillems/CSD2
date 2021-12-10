#ifndef _OSCILLATOR_
#define _OSCILLATOR_
#include <iostream>

class Oscillator {

public:
    //constructor destructor
    Oscillator(double frequency, double samplerate);
    ~Oscillator();

    //return current sample
    double getSample();
    //go to next sample
    void tick();

    //getters and setters
    void setFrequency(double frequency);
    double getFrequency();

    void setSamplerate(double samplerate);
    double getSamplerate();   

    
protected:
    virtual void calculate() = 0;
    double frequency;
    double samplerate;
    double sample;
    double phase;
    double amplitude;
};


#endif