import os
import sys
import numpy as np
from scipy.signal import get_window
from scipy.fftpack import fft,ifft
from scipy.io.wavfile import read
from scipy.io.wavfile import write
from scipy.fft import fft, fftfreq
from scipy.fft import rfft, rfftfreq
from scipy.fft import irfft
import matplotlib.pyplot as plt
import math
from numpy import random
import ephem
import datetime

#Planet information from
#https://rhodesmill.org/pyephem/index.html

#Audio FFT part
#------------------------------------------------------------------------------#
SAMPLE_RATE = 44100
NIQUIST = SAMPLE_RATE / 2
DURATION = 10
PLANET = "planet"
PLANET_NAME = "Neptune"

#number of samples
N = SAMPLE_RATE * DURATION

#make empty array with all frequencies to 0, to fill later.
yf = [0]
for x in range(int(N)):
    yf.append(0)

#all distances from (2000,2022) on the first of january.
#year_time = start year
#num_years = number of frequencies to draw
year_time = 1999
num_years = 100
for x in range(num_years):
    year_time += 1
    plant_result = eval('ephem.' + PLANET_NAME + '(str(year_time))')
    PLANET = plant_result
    print(str(year_time))
    planet_distance = PLANET.earth_distance * ephem.meters_per_au / ephem.c
    print("%.2f sec" % (planet_distance))
    num = 22
    for x in range(num):
        #make an complex array with a real and imaginary part complex(1, amp)
        #yf[frequency]
        yf[int(planet_distance)] = complex(1, random.uniform(8))

#do the reverse fft of yf
Y = ifft(yf)
# print("x=", x)

#normalize new signal
norm_Y = np.int16(Y * (32767 / Y.max()))
# print("normx", norm_x)

write(PLANET_NAME + ".wav", SAMPLE_RATE, norm_Y)

plt.title(PLANET_NAME)
plt.plot(Y[:int(N)])
plt.show()
