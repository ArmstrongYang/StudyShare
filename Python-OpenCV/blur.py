import os
import sys

import cv2


def get_mask(path):
    img = cv2.imread(path, 0)
    value = img[30][150]
    img_resize = cv2.resize(img, (1080, 1080))
    print(img.shape)
    ret, img_dst = cv2.threshold(img_resize, value, 255, cv2.THRESH_BINARY)
    cv2.imwrite(path + '_dst.png', img_dst)
    return img_dst


def blur_image_with_depth_map(image_path, depth_map, debug=True):
    img = cv2.imread(image_path)
    img_depth = cv2.imread(depth_map, 0)
    print(img.shape)
    print(img_depth.shape)
    # print(img)
    # img_dst = cv2.blur(img, (55, 55))
    img_dst = cv2.GaussianBlur(img, (155, 155), 0)
    # img_dst = cv2.bilateralFilter(img, 9, 75, 75)
    cv2.imwrite(image_path + '_dst.png', img_dst)
    mask = get_mask(depth_map)
    width, height, channels = img.shape
    center = (height//2, width//2)
    mixed_clone = cv2.seamlessClone(
        img_dst, img, mask, center, cv2.NORMAL_CLONE)
    # mixed_clone = cv2.seamlessClone(
    #     img_dst, img, mask, center, cv2.MIXED_CLONE)
    # mixed_clone = cv2.seamlessClone(
    #     img_dst, img, mask, center, cv2.MONOCHROME_TRANSFER)
    cv2.imwrite(image_path + '_dst_mixed.png', mixed_clone)


if __name__ == "__main__":
    print(__file__)
    blur_image_with_depth_map("image_source.jpg", "image_depth.png")
    get_mask("image_depth.png")
