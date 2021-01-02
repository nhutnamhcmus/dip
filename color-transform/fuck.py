import math


def hsv2rgb(image):
    dstImage = np.zeros(image.shape, image.dtype)
    for height in range(image.shape[0]):
        for width in range(image.shape[1]):
            hue = image[height, width, 0] / 2.0
            saturation = image[height, width, 1] / 255.0
            value = image[height, width, 2] / 255.0
            k_red = math.fmod((5 + 1.0 * hue / 60), 6)
            k_green = math.fmod((3 + 1.0 * hue / 60), 6)
            k_blue = math.fmod((1 + 1.0 * hue / 60), 6)
            dstImage[height, width, 0] = value - (value * saturation) * math.fmax(0, math.fmin(math.fmin(k_red, 4 - k_red), 1))
            dstImage[height, width, 1]= value - (value * saturation) * math.fmax(0, math.fmin(math.fmin(k_green, 4 - k_green), 1))
            dstImage[height, width, 2]= value - (value * saturation) * math.fmax(0, math.fmin(math.fmin(k_blue, 4 - k_blue), 1))
    return dstImage
