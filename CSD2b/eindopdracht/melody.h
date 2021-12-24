#include <iostream>
#include "ui.h"
#include "math.h"

#pragma once


//create melody class with the according functions
//--------------------------------------------------------------------------------------------//
class Melody {
public:
    
    //constructor, destructor
    Melody();
    ~Melody();

    //getters and setters
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
//--------------------------------------------------------------------------------------------//