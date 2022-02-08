#include "Tremolo.h"
#include "writeToFile.h"
#include "jack_module.h"

#define WRITE_TO_FILE 1
#define WRITE_NUM_SAMPLES 44100


int main() {

    //instantiate tremolo effect
    Tremolo Tremolo(20, 441000);
}