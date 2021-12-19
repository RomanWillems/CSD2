#ifndef _OSCILLATOR_
#define _OSCILLATOR_
#include <iostream>

class Oscillator {

public:
    //constructor destructor
    Oscillator(double samplerate);
    virtual ~Oscillator();

    void initialize(double samplerate);

    //return current sample
    double getSample();
    //go to next sample
    void tick(double frequency);

    //getters and setters
    void setFrequency(double frequency);
    double getFrequency();
    void resetPhase();

    
protected:
    virtual void calculate() = 0;
    double frequency;
    double samplerate;
    double sample;
    double phase;
    double amplitude;

};


#endif