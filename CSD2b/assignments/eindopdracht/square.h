#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include "oscillator.h"


//create a square class with al the functions needed
//--------------------------------------------------------------------------------------------//
class Square : public Oscillator
{
public:
    //constructor and destructor
    Square(double samplerate);
    ~Square();

private:
    // override base class virtual function.
    void calculate() override;
};
//--------------------------------------------------------------------------------------------//

#endif