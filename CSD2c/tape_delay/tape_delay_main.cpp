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
#include "tape_delay.h"


unsigned long chunksize=256;

JackModule jack;
unsigned long samplerate=44100; // default

bool running=true;


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


//TapeDelay(size,  delayMS, feedback, modFrequency, drive)
AudioEffect* effectL = new TapeDelay(samplerate, 500, 0.3, 3, 3);
effectL->setDryWet(0.5);

AudioEffect* effectR = new TapeDelay(samplerate, 500, 0.3, 5, 3);
effectR->setDryWet(0.5);

do {
  jack.readSamples(inbuffer,chunksize);

  for(unsigned int x=0; x<chunksize; x++)
  {


    effectL->processFrame(inbuffer[x], outbuffer[2*x]);
    effectR->processFrame(inbuffer[x], outbuffer[2*x+1]);
  }

  jack.writeSamples(outbuffer,chunksize*2);

 } while(running);

}



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
