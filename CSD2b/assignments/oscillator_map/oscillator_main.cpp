#include "oscillator.h"

int main() {
    int userFreq;
    Oscillator osc(userFreq, 0.5);
    
    bool correctInput = false;
    do {
        std::cout << "Choose frequency in Hz: [0, 22049]" << "\n";
        std::cin >> userFreq;
        correctInput = osc.setFreq(userFreq);
        if (!correctInput) {
            std::cout << "not in range" << "\n";
        }
    } while (!correctInput);
    
    std::cout << "Frequencey of the osc object is: " << osc.getFreq() << "\n";
    std::cout << "Amplitude of the osc object is: " << osc.getAmp() << "\n";



    osc.setAmp(0.9);
    std::cout << " New amplitude of the osc object is: " << osc.getAmp() << "\n";

    //end program
    return 0;
}