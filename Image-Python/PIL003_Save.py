from PIL import Image

if __name__ == '__main__':
    print(__file__)
    img_name = '2015-World-GDP.png'
    im = Image.open(img_name)

    img_save_name = '2015-World-GDP.jpg'
    im.save(img_save_name)
    exit(0)