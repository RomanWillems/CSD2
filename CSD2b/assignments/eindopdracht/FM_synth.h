#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "math.h"
#include "writeToFile.h"
#include "synth.h"

#pragma once

class FM_synth : public Synth {
public:
    FM_synth();
    ~FM_synth();

    void Carrier();
    void Modulator();

    float calculate();
    void tick();
    float getSample();
    float setFrequency();
};