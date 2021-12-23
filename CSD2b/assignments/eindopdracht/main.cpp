
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
#define SAMPLERATE 44100
#define NUMBERPITCHES 8

//start jack audio
//jackd -d coreaudio


// std::string chooseSynth(){

//   UserInput selectSynth;
//   std::cout << "Chose your kind of modulation! (your synth).\n";
//   std::string synthOptions[2] = {"fm", "ring"};
//   int synthNumOptions = 3;
//   std::string synthSelection = selectSynth.retrieveUserSelection(synthOptions, synthNumOptions);
//   return synthSelection;
// }


int main(int argc,char **argv)
{
// create a JackModule instance
JackModule jack;
// init the jack, use program name as JACK client name
jack.init(argv[0]);
double samplerate = jack.getSamplerate();



// FM_synth fmSynth;
// Ring_synth ringSynth;
// Synth* synth = nullptr;
// synth = &fmSynth;

// std::string synthChoise = chooseSynth();

// if(synthChoise == "fm") {
//     synth = &fmSynth;
//   } else if(synthChoise == "ring") { 
//     synth = &ringSynth;
//   }

//call UI class
UserInput UserInput;
// select carrier wave form
std::cout << "Choose carrier waveform.\n";
std::string CarWaveFormOptions[3] = {"sine", "saw", "square"};
int CarNumWaveFormOptions = 3;
std::string CarWaveTypeSelection = UserInput.retrieveUserSelection(CarWaveFormOptions, CarNumWaveFormOptions);

//TODO MELODY

//select modulator wave form
std::cout << "Choose modulator waveform.\n";
std::string ModWaveFormOptions[3] = {"sine", "saw", "square"};
int ModNumWaveFormOptions = 3;
std::string ModWaveTypeSelection = UserInput.retrieveUserSelection(ModWaveFormOptions, ModNumWaveFormOptions);

//select mod frequency
std::cout << "Choose a frequency for your modulator.\n";
int modFreq = UserInput.retrieveValueRange(0, 10000);


//set fm synth params
FM_synth synth;
synth.setCarWaveForm(CarWaveTypeSelection,samplerate);
synth.setModWaveForm(ModWaveTypeSelection,samplerate);
synth.resetPhase();
synth.setModFreq(modFreq);
synth.setRatio(1.2);
synth.setModDepth(50);

// //set ring synth params
// synth->setCarWaveForm(CarWaveTypeSelection,samplerate);
// synth->setModWaveForm(ModWaveTypeSelection,samplerate);
// synth->resetPhase();
// synth->setModFreq(modFreq);

#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < SAMPLERATE; i++) {
    fileWriter.write(std::to_string(synth.calculate()) + "\n");
  }
#else

  float amplitude = 0.15;
  int framecount = 0;
  int interval = 44100;
  int newPitch = 0;
  int length = 0;

  Melody melody;
  melody.nextNote();
  melody.setNoteLength();

  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &amplitude, &framecount, &interval, &newPitch, &melody, &length]
    (jack_default_audio_sample_t *inBuf,
      jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
        outBuf[i] = synth.calculate() * amplitude;
        framecount++;
        if (framecount > interval){
          std::cout << "pitch" << std::endl;
          length++;
          if(length >= 8) {
            length = 0;
          }
          interval = (melody.getNoteLength(length));
          newPitch++;
          if (newPitch >= 8){
            newPitch = 0; 
              }
          synth.setCarPitch(melody.getMidiList(newPitch));
          framecount = 0;

          std::cout << "pitch = " << melody.getMidiList(newPitch) << std::endl;
         }
        }

      amplitude =  0.5;
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
