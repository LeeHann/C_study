#%%
from struct import *

print(f'load struct module ')
# %%
buf = pack('hhl', 1,2,3)
# %%
_data = unpack('hhl', buf) # short short long
print(_data)
# %%
_f = open('t1.bin', 'wb')
_f.write(buf)
_f.close()