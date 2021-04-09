import cv2 as cv

image = cv.imread('photo/L_11.jpg');

cv.imshow('L Lawliet', image);

def rescale_frame(frame, scale=0.75):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    dimesions = (width, height)

    return cv.resize(frame, dimesions, interpolation=cv.INTER_LINEAR)

image_scale = rescale_frame(image)

cv.imshow('L Lawliet Resize', image_scale);

cv.waitKey(0)