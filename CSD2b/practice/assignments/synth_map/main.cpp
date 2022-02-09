#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "writeToFile.h"

//start jack audio with:
//jackd -d coreaudio

#define PI_2 6.28318530717959

int main(int argc,char **argv) 
{

  //create jackmodule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  Sine sine(220, samplerate);

  //assign a function to the JackModule::onProces
  jack.onProcess = [&sine](jack_default_audio_sample_t *inBuf,
      jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    static float amplitude = 0.15;

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = sine.getSample() * amplitude;
      sine.tick();
    }

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
  
  // write 1 second of sampoles to file
  // second parameter overqrite is set to true
  WriteToFile fileWriter("output.csv", true);
  for(int i = 0; i < samplerate; i++) {
      fileWriter.write(std::to_string(sine.getSample()) + "\n");
      sine.tick();
  }
  return 0;
}
