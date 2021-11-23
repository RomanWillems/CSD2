#! /bin.bash

g++ -c speaker.cpp
g++ -c woofer.cpp
g++ -c tweeter.cpp
g++ -c speaker-main.cpp
g++ -o speaker speaker-main.o speaker.o woofer.o tweeter.o