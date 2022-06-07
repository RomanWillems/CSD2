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

#Data retrieval part
#https://rhodesmill.org/pyephem/index.html
#------------------------------------------------------------------------------#
# using now() to get current time
current_time = datetime.datetime.now()

utrecht = ephem.Observer()
utrecht.lat = '52.092876'
utrecht.lon = '5.104480'
utrecht.date = current_time

mars = ephem.Mars()
mars.compute(utrecht)
mars_altitude = mars.alt + 0.0 #in degrees
mars_azimut = mars.az #in degrees

mars_altitude = mars_altitude * 1000
mars_altitude = int(mars_altitude)
mars_altitude = abs(mars_altitude)

mars_azimut = mars_azimut * 100
mars_azimut = int(mars_azimut)
mars_azimut = abs(mars_azimut)

print("mars_azimut =", mars_azimut)
print("mars_altitude =", mars_altitude)

#Audio FFT part
#------------------------------------------------------------------------------#
SAMPLE_RATE = 44100
NIQUIST = SAMPLE_RATE / 2
DURATION = 1

N = SAMPLE_RATE * DURATION

#Make an empty array with the length of the NIQUIST * 2
yf = [0]*int(NIQUIST + 1)
#num = number of frequencies to draw
num = mars_azimut
for x in range(num):
    #make an complex array with a real and imaginary part complex(1, amp)
    #yf[frequency]
    yf[random.randint(NIQUIST)] = complex(1, random.uniform(mars_altitude))

xf = rfftfreq(N, 1 / SAMPLE_RATE)
plt.plot(xf, np.abs(yf))
plt.show()

x = ifft(yf)
# print("x=", x)

#normalize new signal
norm_x = np.int16(x * (32767 / x.max()))
# print("normx", norm_x)

write("Mars.wav", SAMPLE_RATE, norm_x)

plt.plot(x[:1000])
plt.show()
