#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
#include <iostream>

class Instrument {
public:
    //constructor destructor
    Instrument(std::string _sound);
    ~Instrument();

    //methods
    void play();
protected:
    std::string sound;
    
};

#endif