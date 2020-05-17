import scipy.io.wavfile
import struct
import numpy

FSample, samples = scipy.io.wavfile.read('1.wav')

for sample in samples:
  (L,R) =struct.unpack('>HH', sample)
  print(hex(L),hex(R))


    s = serial.Serial('COM4', baudrate=2000000)

FSample, samples = scipy.io.wavfile.read('1.wav')

for sample in samples:
  (L,R) =struct.unpack('>HH', sample)

  s.write(hex(R).encode())
  s.write(hex(L).encode())


import numpy as np

volume = 1    # range [0.0, 1.0]
fs = 44100       # sampling rate, Hz, must be integer
duration = 10   # in seconds, may be float
f =440       # sine frequency, Hz, may be float

# generate samples, note conversion to float32 array
samples = (np.sin(2*np.pi*np.arange(fs*duration)*f/fs)).astype(np.float32)
print(samples)
for sample in samples:
  (L,R) =struct.unpack('>HH', sample)
  s.write(bytes(hex(L),'utf-8'))
  s.write(bytes(hex(L),'utf-8'))
