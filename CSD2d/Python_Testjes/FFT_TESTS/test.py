import numpy as np
import sys
import os
from matplotlib import pyplot as plt
from scipy.fft import fft, fftfreq
from scipy.fft import rfft, rfftfreq
from scipy.fft import irfft
from scipy.io.wavfile import read
from scipy.io.wavfile import write

SAMPLE_RATE = 44100 #hz


infile = "tape_chimes.wav"
#read input file
(samplerate, input_data) = read(infile)
print("samplerate =", samplerate)
print("inputdata =", input_data)
