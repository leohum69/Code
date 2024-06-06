import cv2
print(cv2.__version__)
mycam = cv2.VideoCapture(0)
mycam.set(cv2.CAP_PROP_FRAME_HEIGHT,1920)
mycam.set(cv2.CAP_PROP_FRAME_WIDTH,1080)

while True:
    ignore, frame = mycam.read()
    grayframe = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    cv2.imshow('lol',frame)
    cv2.moveWindow('lol',0,0)
    if cv2.waitKey(1) == ord('q'):
        break

mycam.release()