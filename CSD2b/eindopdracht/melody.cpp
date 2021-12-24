#include "melody.h"


//melody constructor and destructor
//--------------------------------------------------------------------------------------------//
Melody::Melody() {}

Melody::~Melody() {}

//midi note generator
//--------------------------------------------------------------------------------------------//
void Melody::nextNote()
{
    //generate random pitches
    srand(time(NULL));
    for (int i = 0; i < noteAmount; i++)
    {
        int rnd = rand() % 40 + 35;
        Notes[i] = rnd;
    }
}

float Melody::getMidiList(int count) 
{
    return Notes[count];
}

//midi note length generator
//--------------------------------------------------------------------------------------------//
void Melody::setNoteLength()
{
    srand(time(NULL));
    for (int i = 0; i < noteLengthAmount; i++)
    {
        int rnd = rand() % (20 + 10) * 1048;
        noteLength[i] = rnd;
    }
}

float Melody::getNoteLength(int count)
{
    return noteLength[count];
}
