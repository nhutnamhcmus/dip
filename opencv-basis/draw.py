import cv2 as cv
import numpy as np

blank = np.zeros((500, 500), dtype='uint8')

# image = cv.imread('photo/L_11.jpg')
# cv.imshow('L Lawliet', image)

# 1. Draw a blank
cv.imshow('Blank', blank)

# 2. Draw 
cv.waitKey(0)