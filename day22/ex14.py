#%%
from struct import *

_f = open('t2.bin', 'rb')
line = _f.readline()
buf = unpack('fihBB', line)

for i in buf :
  print(i)
  
_f.close()