#include "melody.h"

Melody::Melody() : UserInput() {}

Melody::~Melody() {}

void Melody::nextNote()
{
    //generate random numbers
    srand(time(NULL));
    for (int i = 0; i < noteAmount; i++)
    {
        int rnd = rand() % 40 + 30;
        Notes[i] = rnd;
        std::cout << "Notes" << Notes[i] << std::endl;
    }
}

float Melody::getMidiList(int count) 
{
    return Notes[count];
}

void Melody::setNoteLength()
{
    srand(time(NULL));
    for (int i = 0; i < noteLengthAmount; i++)
    {
        int rnd = rand() % (20 + 10) * 1048;
        noteLength[i] = rnd;
        std::cout << "Notes" << Notes[i] << std::endl;
    }
}

float Melody::getNoteLength(int count)
{
    return noteLength[count];
}