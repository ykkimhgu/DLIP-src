import cv2
import numpy as np

'''
    ┌------------------┐
    |    LOAD IMAGE    |
    └------------------┘   
'''

img = cv2.imread("../image/brick1.png", cv2.IMREAD_COLOR)

if img is None: 
    print("Cannot Open Image !")
    exit()

img = cv2.resize(img, (600, 600))

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)


'''
    ┌------------------┐
    |    TRACKBAR 1    |
    └------------------┘   
'''

trackbarName1 = "Trackbar Windows: Edge"
cv2.namedWindow(trackbarName1)

cv2.createTrackbar("threshold1", trackbarName1, 0, 1000, lambda x : x)
cv2.createTrackbar("threshold2", trackbarName1, 0, 1000, lambda x : x)

cv2.setTrackbarPos("threshold1", trackbarName1, 348)
cv2.setTrackbarPos("threshold2", trackbarName1, 779)

'''
    ┌------------------┐
    |    TRACKBAR 2    |
    └------------------┘   
'''

trackbarName2 = "Trackbar Windows: Line"
cv2.namedWindow(trackbarName2)

cv2.createTrackbar("threshold",     trackbarName2, 0, 255, lambda x : x)
cv2.createTrackbar("minLineLength", trackbarName2, 0, 500, lambda x : x)
cv2.createTrackbar("maxLineGap",    trackbarName2, 0, 500, lambda x : x)

cv2.setTrackbarPos("threshold",     trackbarName2, 149)
cv2.setTrackbarPos("minLineLength", trackbarName2, 196)
cv2.setTrackbarPos("maxLineGap",    trackbarName2, 55)

while  cv2.waitKey(1) != ord('q'):

    thresh1 = cv2.getTrackbarPos("threshold1", trackbarName1)
    thresh2 = cv2.getTrackbarPos("threshold2", trackbarName1)

    thresh = cv2.getTrackbarPos("threshold",            trackbarName2)
    minlineLen = cv2.getTrackbarPos("minLineLength",    trackbarName2)
    maxlineGap = cv2.getTrackbarPos("maxLineGap",       trackbarName2)

    canny   = cv2.Canny(gray, thresh1, thresh2)

    lines = cv2.HoughLinesP(canny, 1, np.pi/180, threshold=thresh, minLineLength=minlineLen, maxLineGap=maxlineGap)

    cv2.imshow(trackbarName1, canny)