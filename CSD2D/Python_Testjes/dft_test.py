# Link to this test, plotting waves.
# https://pythonnumericalmethods.berkeley.edu/notebooks/chapter24.01-The-Basics-of-waves.html

import matplotlib.pyplot as plt
import numpy as np

plt.style.use('seaborn-poster')

#sampling rate
sr = 100

#sampling interval
ts = 1.0/sr

#arange(start, stop ,steps)
t = np.arange(0,1,ts)

#-------------------------------------------------------------------------#
#make sine's and add up to x
# x = amp * sine(2pi*frequency*time)
freq = 1.
x = 3*np.sin(2*np.pi*freq*t)

freq = 4
x += np.sin(2*np.pi*freq*t)

freq = 7
x += 0.5 * np.sin(1*np.pi*freq*t)
#-------------------------------------------------------------------------#

#make a DFT function
#Function to calculate the discrete Fourier Transform of a 1D real-valued signal x
def DFT(x):
    N = len(x)
    n = np.arange(N)
    k = n.reshape((N, 1)) #Gives a new shape to an array without changing its data.
    e = np.exp(-2j * np.pi * k * n / N) #calculate exponential
    X = np.dot(e, x) #multiply things in array
    return X

X = DFT(x)

#calculate the frequency
N = len(X)
n = np.arange(N)
T = N/sr
freq = n/T

plt.figure(figsize = (8, 6))
plt.stem(freq, abs(X), 'b', \
         markerfmt=" ", basefmt="-b")
plt.xlabel('Freq (Hz)')
plt.ylabel('Amplitude')

plt.show()
