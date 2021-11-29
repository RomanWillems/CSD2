#include "flute.h"

Flute::Flute(std::string sound) : Instrument(sound) {
    
    std::cout << "constructor flute: sound= \n" << sound << "\n";

} 

Flute::~Flute() {

    std::cout << "deconstructor flute: sound = \n" << sound << "\n";
}

void Flute::whistle() {
    
    std::cout << "whistleling on my flute" << "\n";
}
