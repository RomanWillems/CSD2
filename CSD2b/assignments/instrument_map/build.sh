#!/bin/bash

g++ -c instrument.cpp
g++ -c instrument_main.cpp
g++ -o instrument instrument.o instrument_main.o