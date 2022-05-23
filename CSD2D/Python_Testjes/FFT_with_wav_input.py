import os
import sys
import numpy as np
from scipy.signal import get_window
from scipy.fftpack import fft,ifft
from scipy.io.wavfile import read
from scipy.io.wavfile import write
import matplotlib.pyplot as plt
import math
import random

SAMPLE_RATE = 44100 #hz

def fft(infile, outfile):

    NT16_FAC = (2**15)-1
    INT32_FAC = (2**31)-1
    INT64_FAC = (2**63)-1
    norm_fact = {'int16':INT16_FAC, 'int32':INT32_FAC, 'int64':INT64_FAC,'float32':1.0,'float64':1.0}

    #TODO:
    # read input file and if necessary, convert it to mono
    (fs,x) = read(infile)
    #print x.shape
    # take only first (mono) channel
    x=x[:,0]
    #print x.shape
    x = np.float32(x)/norm_fact[x.dtype.name]
    plt.plot(x[:200])
    plt.show()

#TODO:
# FFT ON WAV FILE

#TODO:
# RFFT ON WAV FILE

#TODO:
# WRITE AND PLOT WAV FILE

if __name__ == '__main__':
  if len(sys.argv) < 2:
    print("Please enter input filename")
    sys.exit()
  infile=sys.argv[1]
  basename=os.path.splitext(sys.argv[1])[0]
  extension=os.path.splitext(sys.argv[1])[1]
  outfile=basename + "_out" + extension
  print(outfile)
  fft(infile,outfile)
