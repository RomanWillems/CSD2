#include "instrument.h"

int main()
{
    int instrumentInput;
    std::cout << "bongo: (1) " << std::endl;
    std::cout << "flute: (2) " << std::endl;
    std::cin >> instrumentInput;


    Instrument bongo("boemboem");
    Instrument flute("fieeuw");
    
    if (instrumentInput == 1){
        bongo.play();
    } else {
        flute.play();
    }
}