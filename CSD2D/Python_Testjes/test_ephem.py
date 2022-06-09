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
import random
import ephem
import datetime

# importing datetime module for now()
import datetime


# using now() to get current time
current_time = datetime.datetime.now()

#alle afstanden van (2000tm2022/1/1) krijgen van gekozen planeet.
year_time = 1999
num_years = 23
for x in range(num_years):
    year_time += 1
    mars = ephem.Mars(str(year_time))
    print(str(year_time))
    planet_distance = mars.earth_distance * ephem.meters_per_au / ephem.c
    print("%.2f sec" % (planet_distance))



# neptune = ephem.Neptune(current_time)
# print("%.2f sec" % (neptune.earth_distance * ephem.meters_per_au / ephem.c))





















# utrecht = ephem.Observer()
# utrecht.lat = '52.092876'
# utrecht.lon = '5.104480'
# utrecht.date = current_time
#
# mars = ephem.Mars()
# mars.compute(utrecht)
# mars_altitude = mars.alt + 0.0 #in degrees
# mars_azimut = mars.az #in degrees
#
# print("mars_azimut =", mars_azimut)
# print("mars_altitude =", mars_altitude)
