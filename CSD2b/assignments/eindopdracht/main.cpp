
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

FM_synth synth(samplerate);
synth.resetPhase();
synth.setModFreq(400);
synth.setCarPitch(50);
synth.setRatio(4);
synth.setModIndex();

float amplitude = 0.15;

#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < SAMPLERATE; i++) {
    fileWriter.write(std::to_string(synth.getSample()) + "\n");
    synth.tick();
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
        outBuf[i] = synth.getSample() * amplitude;
        synth.tick();
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
