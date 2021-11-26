#include "instrument.h"


Instrument::Instrument(std::string _sound)
{
    sound = _sound;
}

Instrument::~Instrument()
{
    
}

void Instrument::play()
{
    std::cout << sound << std::endl;
}


