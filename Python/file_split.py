import os

if __name__=='__main__':
    print(__file__)
    dir = os.getcwd()
    print(dir)
    filelist = os.listdir(dir)
    print(filelist)
    exit(0)