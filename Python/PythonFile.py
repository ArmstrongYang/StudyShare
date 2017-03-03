import os

path_list = os.listdir()
separator = [' ','-','_']

for l in path_list:
    for s in separator:
        print(l.split(s))

if __name__=='__main__':
    print(__file__)
    dir = os.getcwd()
    print(dir)
    
    exit(0)