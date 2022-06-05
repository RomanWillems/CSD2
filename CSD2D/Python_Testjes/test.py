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

#Make an empty array with the length of the NIQUIST * 2
yf = [0]*int(NIQUIST + 1)
#make an complex array with a real and imaginary part complex(1, amp)
#yf[positie]
yf[2000] = complex(1, 20000)
