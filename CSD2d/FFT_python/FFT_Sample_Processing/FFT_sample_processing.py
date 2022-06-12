import numpy as np
import sys
import os
from matplotlib import pyplot as plt
from scipy.fft import fft, fftfreq
from scipy.fft import rfft, rfftfreq
from scipy.fft import irfft
from scipy.io.wavfile import read
from scipy.io.wavfile import write

SAMPLE_RATE = 44100 #hz


def do_fft(infile,outfile):

    #read input file:
    (samplerate, input_data) = read(infile)
    print("samplerate =", samplerate)
    # #make mono
    input_data=input_data[:,0]
    #normalize x en set to 16bit integer
    input_data= np.int16((input_data/ input_data.max()) * 32767)

    length = input_data.shape[0] / samplerate

    # Number of samples in normalized_tone
    N = samplerate * length
    print("N=", N)

    yf = rfft(input_data)
    xf = rfftfreq(int(N), 1 / samplerate)

    # # # flip the frequencys
    # yf = np.flip(yf)

    #roll the frequencys ahead or back in the spectrum (only with full list)
    yf = np.roll(yf, -20000)

    print("yf =", yf)

    #decompose spectrum
    YMag=abs(yf)
    YPhase=np.angle(yf)
    #set phase
    YPhase = 0
    # reconstruct spectrum
    yf = YMag*(np.cos(YPhase) + 1j*np.sin(YPhase))

    plt.plot(xf, np.abs(yf))
    plt.show()

    output_data = irfft(yf)

    #normalize new signal
    output_data = np.int16(output_data * (32767 / output_data.max()))

    write(outfile, samplerate, output_data)

if __name__ == '__main__':
  if len(sys.argv) < 2:
    print("Please enter input filename")
    sys.exit()
  infile=sys.argv[1]
  basename=os.path.splitext(sys.argv[1])[0]
  extension=os.path.splitext(sys.argv[1])[1]
  outfile=basename + "_out" + extension
  print(outfile)
  do_fft(infile,outfile)
