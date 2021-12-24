
#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "square.h"
#include "saw.h"
#include "writeToFile.h"
#include "oscillator.h"
#include "FM_synth.h"
#include "Ring_synth.h"
#include "ui.h"
#include "melody.h"

#define WRITE_TO_FILE 0


//The jack module's and Write to file module's are given to me by Ciska Vriezenga and Marc Groenewegen.
//The synth created is a development from the gaven lessons by Ciska and Marc.

int main(int argc,char **argv)
{
// create a JackModule instance
JackModule jack;
// init the jack, use program name as JACK client name
jack.init(argv[0]);
double samplerate = jack.getSamplerate();

//UI:
//--------------------------------------------------------------------------------------------//
//call UI class
UserInput UserInput;

std::cout << "--------------------------------------------------\n";
std::cout << "Chose your kind of modulation! (your synth).\n";
std::string synthOptions[2] = {"fm", "ring"};
int synthNumOptions = 2;
std::string synthSelection = UserInput.retrieveUserSelection(synthOptions, synthNumOptions);
std::cout << "--------------------------------------------------\n";

// select carrier wave form
std::cout << "Choose carrier waveform.\n";
std::string CarWaveFormOptions[3] = {"sine", "saw", "square"};
int CarNumWaveFormOptions = 3;
std::string CarWaveTypeSelection = UserInput.retrieveUserSelection(CarWaveFormOptions, CarNumWaveFormOptions);
std::cout << "--------------------------------------------------\n";

//select modulator wave form
std::cout << "Choose modulator waveform.\n";
std::string ModWaveFormOptions[3] = {"sine", "saw", "square"};
int ModNumWaveFormOptions = 3;
std::string ModWaveTypeSelection = UserInput.retrieveUserSelection(ModWaveFormOptions, ModNumWaveFormOptions);
std::cout << "--------------------------------------------------\n";

//select mod frequency
std::cout << "Choose a frequency for your modulator.\n";
int modFreq = UserInput.retrieveValueRange(0, 10000);
std::cout << "--------------------------------------------------\n";


//Synth selection.
//--------------------------------------------------------------------------------------------//
//make a pointer for synth
Synth* synth = nullptr;
if (synthSelection == "fm") {
  //if user selection is FM make an FM synth and fill te according parameters
  synth = new FM_synth;
  ((FM_synth*)synth) -> setCarWaveForm(CarWaveTypeSelection,samplerate);
  ((FM_synth*)synth) -> setModWaveForm(ModWaveTypeSelection,samplerate);
  ((FM_synth*)synth) -> resetPhase();
  ((FM_synth*)synth) -> setModFreq(modFreq);
  ((FM_synth*)synth) -> setModDepth(50);
} else if (synthSelection == "ring") {
  //if user selection is Ring make an Ring synth and fill te according parameters
  synth = new Ring_synth;
  ((Ring_synth*)synth)->setCarWaveForm(CarWaveTypeSelection,samplerate);
  ((Ring_synth*)synth)->setModWaveForm(ModWaveTypeSelection,samplerate);
  ((Ring_synth*)synth)->resetPhase();
  ((Ring_synth*)synth)->setModFreq(modFreq);
}

//Write to file
//--------------------------------------------------------------------------------------------//
//make and output file with al the samples, so you can plot the output if you want
#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < samplerate; i++) {
    fileWriter.write(std::to_string(synth->calculate()) + "\n");
  }
#else

//generate sound and melody
//--------------------------------------------------------------------------------------------//
  float amplitude = 0.05;
  int framecount = 0;
  int interval = 44100;
  int newPitch = 0;
  int length = 0;

//create a melody class and call the melody functions
  Melody melody;
  melody.nextNote();
  melody.setNoteLength();

  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &amplitude, &framecount, &interval, &newPitch, &melody, &length]
    (jack_default_audio_sample_t *inBuf,
      jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
        outBuf[i] = synth->calculate() * amplitude;
        framecount++;
        if (framecount > interval){
          length++;
          if(length >= 8) {
            length = 0;
          }
          interval = (melody.getNoteLength(length));
          newPitch++;
          if (newPitch >= 8){
            newPitch = 0; 
              }
          //set the midipitch according to the melody list
          synth->setMidiPitch(melody.getMidiList(newPitch));
          framecount = 0;
          //print the pitch for the user
          std::cout << "pitch = " << melody.getMidiList(newPitch) << std::endl;
         }
        }

      amplitude =  0.3;
    return 0;
  };
  
  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }

#endif
  //end the program
  return 0;

} 
