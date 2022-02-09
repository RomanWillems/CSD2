#include "instrument.h"


Instrument::Instrument(std::string _sound)
{
    std::cout << "constructor Instrument:\n";
    this->sound = _sound;
}

Instrument::~Instrument()
{
    std::cout << "destructor Instrument\n";
}

void Instrument::play()
{
    std::cout << sound << "is playing\n";
}


