import numpy as np
from matplotlib import pyplot as plt
from scipy.io.wavfile import write
from scipy.fft import fft, fftfreq
from scipy.fft import rfft, rfftfreq
from scipy.fft import irfft

SAMPLE_RATE = 44100 #hz
DURATION = 5 #seconds

#TODO:
# READ WAV file
# FFT ON WAV FILE
# RFFT ON WAV FILE
# WRITE AND PLOT WAV FILE

# Number of samples in normalized_tone
N = SAMPLE_RATE * DURATION

yf = rfft(normalized_sine)
xf = rfftfreq(N, 1 / SAMPLE_RATE)

# The maximum frequency is half the sample rate (nyquist)
points_per_freq = len(xf) / (SAMPLE_RATE / 2)

# Target frequency is 4000 Hz
target_freq = int(points_per_freq * 4000)

yf[target_freq - 1 : target_freq + 2] = 0

#inverse fft
new_sig = irfft(yf)

#normalize new signal
norm_new_sig = np.int16(new_sig * (32767 / new_sig.max()))

write("clean.wav", SAMPLE_RATE, norm_new_sig)

#plot only first 1000 samples
plt.plot(new_sig[:1000])
plt.show()
