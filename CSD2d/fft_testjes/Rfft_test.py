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
NIQUIST = SAMPLE_RATE / 2
DURATION = 10
# Number of samples in normalized_tone
N = SAMPLE_RATE * DURATION
#
# yf = rfft(sin1)
# print("lengte lijst", len(yf))

#Make an empty array with the length of the NIQUIST * 2
yf = [0]*int((N/2) + 1)
#make an complex array with a real and imaginary part complex(1, amp)
#yf[positie]
yf[2000] = complex(1, 20000)


xf = rfftfreq(N, 1 / SAMPLE_RATE)

# print("yf =", yf)
plt.plot(xf, np.abs(yf))
plt.show()
#
x = ifft(yf)
#
plt.plot(x[:100])
plt.show()
