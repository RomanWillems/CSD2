#!/bin/bash

g++ -c oscillator.cpp
g++ -c oscillator_main.cpp
g++ -o oscillator oscillator.o oscillator_main.o