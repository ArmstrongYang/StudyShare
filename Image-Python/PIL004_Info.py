'''
下面的程序用来快速确定图片属性：

确定图片属性

from __future__ import print_function
import sys
from PIL import Image

for infile in sys.argv[1:]:
    try:
        with Image.open(infile) as im:
            print(infile, im.format, "%dx%d" % im.size, im.mode)
    except IOError:
        pass
'''

from PIL import Image
from PIL.ExifTags import TAGS

def info(file):
    im = Image.open(file)
    #im.show()
    print(im.format, im.size, im.mode)
    #print(im.info)


def exif(fname):
    """Get embedded EXIF data from image file."""
    ret = {}
    try:
        img = Image.open(fname)
        if hasattr( img, '_getexif' ):
            exifinfo = img._getexif()
            if exifinfo != None:
                for tag, value in exifinfo.items():
                    decoded = TAGS.get(tag, tag)
                    ret[decoded] = value
    except IOError:
        print ('IOERROR ' + fname)
    return ret


def tags(file):
    tag = exif(file)
    #print(tag)
    #for i in tag:
    #    print(i, tag[i])
    print(tag['XPKeywords'])

if __name__ == '__main__':
    print(__file__)
    info('2015-World-GDP.png')
    info('Shanghai-Beauty.jpg')
    #exif = exif('Shanghai-Beauty.jpg')
    tags('Shanghai-Beauty.jpg')
   
    #exit(0)