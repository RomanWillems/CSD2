#include "instrument.h"

class Bongo : public Instrument {

public:
    //constructor and destructor
    Bongo(std::string _sound);
    ~Bongo();

    //methods
    void drum();
};