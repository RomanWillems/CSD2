#include <iostream>

//-----------------------------------------------------------------------------//

struct ChooseInstrument {
    int InstrumentInput;
    ChooseInstrument() {
        std::cout << "bongo: (1) " << std::endl;
        std::cout << "flute: (2) " << std::endl;
        std::cin >> InstrumentInput;
    }
};

ChooseInstrument InstrumentChoise;

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

    std::cout << "choosen instrument=  " << InstrumentChoise.InstrumentInput << '\n';

    Instrument bongo("boemboem");
    Instrument flute("fieeuw");
    
    bongo.play();
    flute.play();
}