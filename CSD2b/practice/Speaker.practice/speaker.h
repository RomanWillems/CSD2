#include <iostream>
#include "woofer.h"
#include "Tweeter.h"

class Speaker {
public:
    Speaker();
    ~Speaker();
    void make_sound(float freq);
    float filter_freq; // filter cutoff frequency

    Tweeter tweeter;
    Woofer woofer_big;
    Woofer woofer_normal;

    // woofer
    // tweeter
    // amp
    // filter
};

