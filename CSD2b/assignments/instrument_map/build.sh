#!/bin/bash

g++ -c bongo.cpp
g++ -c flute.cpp
g++ -c instrument.cpp
g++ -c instrument_main.cpp
g++ -o instrument bongo.o flute.o instrument.o instrument_main.o