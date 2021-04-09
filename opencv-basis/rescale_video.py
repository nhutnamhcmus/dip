import cv2 as cv

capture = cv.VideoCapture('video/bet_on_shirou.mp4')


def change_res(width, height):
    # Work for: Live video
    capture.set(3, width)
    capture.set(4, height)

def rescale_frame(frame, scale=0.75):
    # Work for: Image, Video, Live video
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    dimesions = (width, height)

    return cv.resize(frame, dimesions, interpolation=cv.INTER_LINEAR)


while True:
    isTrue, frame = capture.read()

    frame_resize = rescale_frame(frame)
    cv.imshow('Video', frame)

    cv.imshow('Video Resize', frame_resize)
    
    if (cv.waitKey(20) & 0xFF == ord('d')):
        break

capture.close()
cv.destroyAllWindows()

