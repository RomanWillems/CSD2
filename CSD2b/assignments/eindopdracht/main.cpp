
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

//start jack audio
//jackd -d coreaudio
int main(int argc,char **argv)
{
  std::cout << "doet main het\n";
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  std::cout << "doet jacky d het\n";

  FM_synth synth(40, samplerate);

  std::cout << "doet fm synth het\n";

  float amplitude = 0.15;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = synth.getSample() * amplitude;
      synth.tick();
    }

    amplitude =  0.5;
    return 0;
  };

  jack.autoConnect();

  
  //Write the values of the waveform in to an csv file 
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < 500; i++) {
    fileWriter.write(std::to_string(synth.getSample()) + "\n");
    synth.tick();
  }

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
  //end the program
  return 0;

} // main()
