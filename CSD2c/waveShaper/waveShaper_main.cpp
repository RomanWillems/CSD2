/**********************************************************************
*          Copyright (c) 2022, Hogeschool voor de Kunsten Utrecht
*                      Hilversum, the Netherlands
*                          All rights reserved
***********************************************************************
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.
*  If not, see <http://www.gnu.org/licenses/>.
***********************************************************************
*
*  File name     : panning.cpp
*  System name   : jack_module
*
*  Description   : example of stereo panning where a mono input signal is
*                    amplitude-panned between left and right outputs
*
*
*  Author        : Marc_G
*  E-mail        : marc.groenewegen@hku.nl
*
**********************************************************************/

#include <iostream>
#include <string>
#include <math.h>
#include <thread>
#include <unistd.h> // sleep
#include "jack_module.h"
#include "keypress.h"
#include "bufferDebugger.h"

#include "waveShaper.h"


unsigned long chunksize=256;

JackModule jack;
unsigned long samplerate=44100; // default

bool running=true;

#define BUFFERSIZE 1000

float totaal;
int number_ints = 1000; //3000 - -3000

void job_1(){
      for (int i = 0; i< number_ints; i++){
          totaal++;
      }
  }

void job_2(){
    for (int i = 0; i< number_ints; i++){
          totaal--;
      }
  }

static void filter(){

  float *inbuffer = new float[chunksize];
  float *outbuffer = new float[chunksize*2];
  // float wavetableBuffer[BUFFERSIZE];

  WaveShaper wave(BUFFERSIZE);
  // wave.genWaveshape(10.0);
  wave.genWaveShapeOscillator(WaveShaper::waveForm::SINE, 10);

  for(int i = 0; i < BUFFERSIZE; i++){
    std::thread thread_1(job_1);
    std::thread thread_2(job_2);

    thread_1.join();
    thread_2.join();

    wave.generateWave(totaal);
}

wave.plot_waveshaper();

    std::cout << "\n***** DONE ***** "
    << "\nOutput is written to file output.csv" << std::endl;

  do {
    jack.readSamples(inbuffer,chunksize);

    for(unsigned int x=0; x<chunksize; x++)
    {

      float amp_left=0.2;
      float amp_right=0.2;

      outbuffer[2*x] = amp_left * wave.interpolation(inbuffer[x]);
      outbuffer[2*x+1] = amp_right * wave.interpolation(inbuffer[x]);
    }

    jack.writeSamples(outbuffer,chunksize*2);

  } while(running);

} // filter()



int main(int argc,char **argv){






char command='@';
  jack.setNumberOfInputChannels(1);
  // jack.setNumberOfOutputChannels(2);
  jack.init(argv[0]); // use program name as JACK client name
  jack.autoConnect();
  samplerate=jack.getSamplerate();
  std::cerr << "Samplerate: " << samplerate << std::endl;

  std::thread filterThread(filter);

  while(command != 'q')
  {
    if(keypressed()) {
      command = getchar();

      if(command == '+' || command == '=') {
        std::cout << "hoi je klikt plus =" << std::endl;
      };
      if(command == '-'){
        std::cout << "hoi je klikt = -" << std::endl;
      };
    }
    usleep(100000);
  }

  running=false;
  filterThread.join();

  jack.end();

  return 0;
} // main()
