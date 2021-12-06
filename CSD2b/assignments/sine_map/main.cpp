#include <iostream>
#include "sine.h"
#include "writeToFile.h"

int main() {
    // create a sine wave
    Sine sine(220);
    std::cout << "sine fq= " << sine.getFrequency() << "\n";
    sine.setFrequency(10);
    std::cout << "sine fq= " << sine.getFrequency() << "\n";

    // write 1 second of sampoles to file
    // second parameter overqrite is set to true
    WriteToFile fileWriter("output.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
        fileWriter.write(std::to_string(sine.getSample()) + "\n");
        sine.tick();
  }
  return 0;
}