#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "square.h"
#include "saw.h"
#include "writeToFile.h"

//start jack audio
//jackd -d coreaudio

#define WRITE_TO_FILE 0


int main(int argc,char **argv)
{

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  Saw sine(220, samplerate);


#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < 500; i++) {
    fileWriter.write(std::to_string(sine.getSample()) + "\n");
    sine.tick();
  }
#else

  float amplitude = 0.15;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&sine, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = sine.getSample() * amplitude;
      sine.tick();
    }

    amplitude = 0.5;
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

} // main()
