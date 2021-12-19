#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include "oscillator.h"


class Square : public Oscillator
{
public:
    //constructor and destructor
    Square(double samplerate);
    ~Square();



private:
    //calculate the next sample according to square calculation
    // override base class virtual function.
    void calculate() override;

};

#endif