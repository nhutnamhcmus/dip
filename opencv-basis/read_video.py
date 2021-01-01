import cv2 as cv

capture = cv.VideoCapture('video/bet_on_shirou.mp4')

while True:
    isTrue, frame = capture.read()
    cv.imshow('Video', frame)
    
    if (cv.waitKey(20) & 0xFF == ord('d')):
        break

capture.close()
cv.destroyAllWindows()