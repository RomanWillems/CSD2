#include <iostream>

class Oscillator {
public:
    Oscillator(float freq, float amp);
    ~Oscillator();
    
    //setters and getters
    bool setFreq(float freq);
    float getFreq();

    void setAmp(float amp);
    float getAmp();

protected:
    float freq;
    float amp;
};