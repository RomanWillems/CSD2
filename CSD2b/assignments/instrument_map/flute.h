#include "instrument.h"

class Flute : public Instrument {

public:
    //constructor destructor
    Flute(std::string _sound);
    ~Flute();

    //methods
    void whistle();
};