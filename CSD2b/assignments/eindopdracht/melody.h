#include <iostream>
#include "ui.h"
#include "math.h"

#pragma once

class Melody : public UserInput{
public:

    Melody();
    ~Melody();

    void nextNote();
    float getMidiList(int count);
    void setNoteLength();
    float getNoteLength(int count);


protected:  

    int noteAmount = 8;
    int Notes[8] = {};
    int midiList[8];
    int note = 0;
    int noteLength[8] = {};
    int noteLengthAmount = 8;

};