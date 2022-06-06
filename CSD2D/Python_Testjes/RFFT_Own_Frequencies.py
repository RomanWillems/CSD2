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

SAMPLE_RATE = 44100
NIQUIST = SAMPLE_RATE / 2
DURATION = 1

N = SAMPLE_RATE * DURATION

#Make an empty array with the length of the NIQUIST * 2
yf = [0]*int(NIQUIST + 1)
#num = number of frequencies to draw
num = 10
for x in range(num):
    #make an complex array with a real and imaginary part complex(1, amp)
    #yf[frequency]
    yf[random.randint(20000)] = complex(1, random.uniform(8))

xf = rfftfreq(N, 1 / SAMPLE_RATE)
plt.plot(xf, np.abs(yf))
plt.show()

x = ifft(yf)
print("x=", x)

#normalize new signal
norm_x = np.int16(x * (32767 / x.max()))

write("gen_wave.wav", SAMPLE_RATE, norm_x)

plt.plot(x[:100])
plt.show()
