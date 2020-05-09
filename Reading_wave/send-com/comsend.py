import serial
import scipy.io.wavfile
import struct
import numpy
import time
import random as a
import wave
s = serial.Serial('COM4', baudrate=9600 )
Wave_read = wave.open('1.wav', 'rb')
nchannels, sampwidth, framerate, nframes, comptype, compname = Wave_read.getparams()
print(framerate)

while(1):
    s.write(Wave_read.readframes(1))