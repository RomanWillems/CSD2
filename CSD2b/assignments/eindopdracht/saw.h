#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
    //constructor and destructor
    Saw(double samplerate);
    ~Saw();

private:
    // override base class virtual function.
    void calculate() override;
};

#endif