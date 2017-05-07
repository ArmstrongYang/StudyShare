from PIL import Image
import os, sys

dir = os.getcwd()
filelist = os.listdir(dir)

for infile in filelist:
    print(infile)
    f, e = os.path.splitext(infile)
    outfile = f + ".jpg"
    if infile != outfile:
        try:
            Image.open(infile).save(outfile)
        except IOError:
            print("cannot convert", infile)

if __name__ == '__main__':
    print(__file__)

    #exit(0)