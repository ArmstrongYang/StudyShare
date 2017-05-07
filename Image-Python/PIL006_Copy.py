'''
裁剪、粘贴、与合并图片
Image类包含还多操作图片区域的方法。如crop()方法可以从图片中提取一个子矩形

从图片中复制子图像

box = im.copy() #直接复制图像
box = (100, 100, 400, 400)
region = im.crop(box)
区域由4-tuple决定，该tuple中信息为(left, upper, right, lower)。 Pillow左边系统的原点（0，0）为图片的左上角。坐标中的数字单位为像素点，所以上例中截取的图片大小为300*300像素^2。
处理子图，粘贴回原图

region = region.transpose(Image.ROTATE_180)
im.paste(region, box)
将子图paste回原图时，子图的region必须和给定box的region吻合。该region不能超过原图。而原图和region的mode不需要匹配，Pillow会自动处理。
'''
from PIL import Image

if __name__ == '__main__':
    print(__file__)
    img_name = '2015-World-GDP.png'
    im = Image.open(img_name)

    img = im.copy() #直接复制图像
    img.show()
    
    box = (100, 100, 600, 600)
    region = im.crop(box)
    region.show()

    region = region.transpose(Image.ROTATE_180)
    im.paste(region, box)
    im.show()

    exit(0)