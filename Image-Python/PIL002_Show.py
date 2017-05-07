from PIL import Image

if __name__ == '__main__':
    print(__file__)
    img_name = '2015-World-GDP.png'
    im = Image.open(img_name)
    im.show()
    #exit(0)