//TODO - indef etc.

#include <iostream>

class Synth
{
public:
    Synth(float midiPitch, double samplerate);
    ~Synth();

    //go to next sample
    void tick();

    double getSample();
    void setMidiPitch(float pitch);

protected:
    float midiPitch;
    double mtof(float pitch);

    double sample;
    Sine sine;

};