'''
创建缩略图

from __future__ import print_function
import os, sys
from PIL import Image

size = (128, 128)

for infile in sys.argv[1:]:
    outfile = os.path.splitext(infile)[0] + ".thumbnail"
    if infile != outfile:
        try:
            im = Image.open(infile)
            im.thumbnail(size)
            im.save(outfile, "JPEG")
        except IOError:
            print("cannot create thumbnail for", infile)
必须指出的是除非必须，Pillow不会解码或raster数据。当你打开一个文件，Pillow通过文件头确定文件格式，大小，mode等数据，余下数据直到需要时才处理。

这意味着打开文件非常快，与文件大小和压缩格式无关。
'''

from PIL import Image
import os, sys

size = (128, 128)

dir = os.getcwd()
filelist = os.listdir(dir)

for infile in filelist:
    outfile = os.path.splitext(infile)[0] + ".thumbnail"
    if infile != outfile:
        try:
            im = Image.open(infile)
            im.thumbnail(size)
            im.save(outfile, "JPEG")
        except IOError:
            print("cannot create thumbnail for", infile)

if __name__ == '__main__':
    print(__file__)

    exit(0)