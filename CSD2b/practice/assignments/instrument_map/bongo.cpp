#include "bongo.h"

//constructor and destructor

Bongo::Bongo(std::string sound) : Instrument(sound) {
    std::cout << "constructor bongo: sound= \n" 
        << sound << "\n";
}

Bongo::~Bongo() {
    std::cout << "deconstructor bongo: sound=\n" 
        << sound << "\n";
}

// methods
void Bongo::drum() {
    std::cout << "is drumming on a bongo." << "\n";
}