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

utrecht = ephem.Observer()
utrecht.lat = '52.092876'
utrecht.lon = '5.104480'
utrecht.date = current_time

mars = ephem.Mars()
mars.compute(utrecht)
mars_altitude = mars.alt
mars_azimut = mars.az

print("mars_azimut =", mars_azimut + 0.0)
print("mars_altitude =", mars_altitude + 0.0)
