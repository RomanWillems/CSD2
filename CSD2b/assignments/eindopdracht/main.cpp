
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

#define WRITE_TO_FILE 0
#define SAMPLERATE 44100
#define NUMBERPITCHES 8

//start jack audio
//jackd -d coreaudio
int main(int argc,char **argv)
{
  
// create a JackModule instance
JackModule jack;
// init the jack, use program name as JACK client name
jack.init(argv[0]);
double samplerate = jack.getSamplerate();


UserInput UserInput;
//int modFreq = UserInput.retrieveValueRange(0, 10000);

//set carrier wave form
std::cout << "choose carrier waveform\n";
std::string CarWaveFormOptions[3] = {"sine", "saw", "square"};
int CarNumWaveFormOptions = 3;
std::string CarWaveTypeSelection = UserInput.retrieveUserSelection(CarWaveFormOptions, CarNumWaveFormOptions);

std::cout << "choose modulator waveform\n";
std::string ModWaveFormOptions[3] = {"sine", "saw", "square"};
int ModNumWaveFormOptions = 3;
std::string ModWaveTypeSelection = UserInput.retrieveUserSelection(ModWaveFormOptions, ModNumWaveFormOptions);


FM_synth synth(samplerate);
synth.setCarWaveForm(CarWaveTypeSelection,samplerate);
synth.setModWaveForm(ModWaveTypeSelection,samplerate);
synth.resetPhase();
synth.setModFreq(100);
synth.setRatio(1.2);
synth.setModDepth(50);




float amplitude = 0.15;

#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < SAMPLERATE; i++) {
    fileWriter.write(std::to_string(synth.calculate()) + "\n");
  }
#else

  int framecount = 0;
  int interval = 10000;
  int newPitch = 0;
  float pitches[NUMBERPITCHES] = {30,53,45,57,58,50,62,64};

  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &amplitude, &framecount, &interval, &newPitch, &pitches]
    (jack_default_audio_sample_t *inBuf,
      jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
        outBuf[i] = synth.calculate() * amplitude;
        framecount++;
        if (framecount > interval){
          std::cout << "pitch" << std::endl;
          framecount = 0;
          newPitch++;
          if (newPitch >= NUMBERPITCHES){
            newPitch = 0; 
              }
          float pitch = pitches[newPitch]; 
          synth.setCarPitch(pitch);

          std::cout << pitch << std::endl;

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
