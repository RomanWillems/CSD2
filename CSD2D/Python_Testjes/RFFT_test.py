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

#lijst van bins fq/bin amount.
#ifft op die bins.
#Pitch shifter.
#Flippen.
#Testen.
SAMPLE_RATE = 44100

DURATION = 1
# TODO:
# FQ spectrum maken met 1 frequency en proberen de ifft daarvan te trekken door een sinus
# te krijgen dan van een bepaald aantal hertz.
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


print("yf =", yf)
plt.plot(xf, np.abs(yf))
plt.show()
#
# x = ifft(yf)
#
# plt.plot(x[:100])
# plt.show()
