#include "speaker.h"

Speaker::Speaker() {
    std::cout << "Constructor called" << std::endl;
    filter_freq=307.2;
}

Speaker::~Speaker() {
    std::cout << "Deconstructor called" << std::endl;
    
}

void Speaker::make_sound(float freq) {
    if(freq >= filter_freq) {
        tweeter.tweet();
    } 
    else {
        woofer_big.woof();
        woofer_normal.woof();
    }

    std::cout << "tadaa" << std::endl;
    std::cout << "Filter Frequency" << filter_freq << std::endl;
}
