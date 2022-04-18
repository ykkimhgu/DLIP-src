"""
# DLIP - Python OpenCV Tutorial
Created by Smart Sensor System Lab
2022-1
> mod: 2022.4.18

This is OpenCV Tutorial for Python (*.py) Version. 
Opens and shows Webcam images
"""



"""## Import OpenCV Library"""

import math
import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt



"""## Open WebCam
> cv.VideoCapture(0) is Not available in Colab/Jupyter
"""

# Press `esc` to stop video 
cap = cv.VideoCapture(0)
while(1):
    _, frame = cap.read()

    cv.imshow('frame',frame)

    # Spatial Filter
    blur = cv.blur(frame,(20,20))
    cv.imshow('blur',blur)

    k = cv.waitKey(5) & 0xFF
    if k == 27:
        break

cv.destroyAllWindows()
cap.release()

