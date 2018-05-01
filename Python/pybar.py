from tqdm import trange
from time import sleep

for i in trange(10, desc='1st loop', leave=True):
    for j in trange(5, desc='2nd loop', leave=True, nested=True):
        for k in trange(100, desc='3nd loop', leave=True, nested=True):
            sleep(0.01)