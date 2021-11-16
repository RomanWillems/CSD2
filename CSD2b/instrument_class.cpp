#include <iostream>



//-----------------------------------------------------------------------------//
class Instrument
{
public:
    Instrument(std::string _sound);
    ~Instrument();
    void play();
    std::string sound;
    
};

void Instrument::play()
{
    std::cout << sound << std::endl;
}

Instrument::Instrument(std::string _sound)
{
    sound = _sound;
}

Instrument::~Instrument()
{
    
}


//-----------------------------------------------------------------------------//
int main()
{
    Instrument trommel("boemboem");
    Instrument flute("fieeuw");
    
    trommel.play();
    flute.play();
}