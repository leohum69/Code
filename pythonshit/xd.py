import cv2

mycam = cv2.VideoCapture(0)

while True:
    ignore,frame1 = mycam.read()
    cv2.imshow('lol1' , frame1)
    cv2.moveWindow('lol1',0,0)
    grey = cv2.cvtColor(frame1,cv2.COLOR_BGR2GRAY)
    cv2.imshow('lol2' , grey)
    cv2.moveWindow('lol2',1280,0)

    cv2.imshow('lol3' , grey)
    cv2.moveWindow('lol3',0,500)

    cv2.imshow('lol4' , frame1)
    cv2.moveWindow('lol4',1280,500)


    if cv2.waitKey(1) == ord('q'):
        break
mycam.release()