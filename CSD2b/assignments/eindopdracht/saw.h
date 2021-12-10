#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
    //constructor and destructor
    Saw(double frequency, double samplerate);
    ~Saw();


private:
    //calculate the next sample according to saw calculation
    // override base class virtual function.
    void calculate() override;
   

};

#endif