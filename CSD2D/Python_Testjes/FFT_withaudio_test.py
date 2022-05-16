import numpy as np
from matplotlib import pyplot as plt
from scipy.io.wavfile import write
from scipy.fft import fft, fftfreq
from scipy.fft import rfft, rfftfreq
from scipy.fft import irfft

SAMPLE_RATE = 44100 #hz
DURATION = 5 #seconds

def gen_sine_wave(freq, sample_rate, duration):
    x = np.linspace(0, duration, sample_rate * duration, endpoint=False)
    frequencies = x * freq
    #2pi np.sin takes radians
    y = np.sin((2 * np.pi) * frequencies)
    return x, y

#generate a 2 hz sine wave that lasts for 5 seconds
_, sin1 = gen_sine_wave(400, SAMPLE_RATE, DURATION)
_, sin2 = gen_sine_wave(4000, SAMPLE_RATE, DURATION)
sin2 = sin2 * 0.3
sin_mixed = sin1 + sin2

#normalize and set to 16bit integer
normalized_sine = np.int16((sin_mixed / sin_mixed.max()) * 32767)

write("mysinewave.wav", SAMPLE_RATE, normalized_sine)

# Number of samples in normalized_tone
N = SAMPLE_RATE * DURATION

yf = rfft(normalized_sine)
xf = rfftfreq(N, 1 / SAMPLE_RATE)

# The maximum frequency is half the sample rate
points_per_freq = len(xf) / (SAMPLE_RATE / 2)

# Our target frequency is 4000 Hz
target_idx = int(points_per_freq * 4000)

yf[target_idx - 1 : target_idx + 2] = 0

#inverse fft
new_sig = irfft(yf)

#normalize new signal
norm_new_sig = np.int16(new_sig * (32767 / new_sig.max()))

write("clean.wav", SAMPLE_RATE, norm_new_sig)

plt.plot(new_sig[:1000])
plt.show()
