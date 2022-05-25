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

SAMPLE_RATE = 44100 #hz
DURATION = 1 #seconds

#TODO:
#FQ spectrum maken met 1 frequency en proberen de ifft daarvan te trekken door een sinus
#te krijgen dan van een bepaald aantal hertz.

def gen_sine_wave(freq, sample_rate, duration):
    x = np.linspace(0, duration, sample_rate * duration, endpoint=False)
    frequencies = x * freq
    #2pi np.sin takes radians
    y = np.sin((2 * np.pi) * frequencies)
    return x, y

#generate a 2 hz sine wave that lasts for 5 seconds
_, sin1 = gen_sine_wave(400, SAMPLE_RATE, DURATION)

# Number of samples in normalized_tone
N = SAMPLE_RATE * DURATION

yf = rfft(sin1)
xf = rfftfreq(N, 1 / SAMPLE_RATE)

plt.plot(xf, np.abs(yf))
plt.show()

# # Number of sample points
# N = 5
# # sample spacing
# T = 1.0 / 800.0
# x = np.linspace(0.0, N*T, N, endpoint=Fals)
# y = np.sin(50.0 * 2.0*np.pi*x) + 0.5*np.sin(80.0 * 2.0*np.pi*x)
#
# yf = fft(y)
# xf = fftfreq(N, T)[:N//2]
#
# print(yf)
#
# import matplotlib.pyplot as plt
# plt.plot(xf, 2.0/N * np.abs(yf[0:N//2]))
# plt.grid()
# plt.show()
