# Tutorial: Camera Calibration



## Tutorial

DLIP Tutorial for Camera Calibration using MATLAB

**Using *"Computer Vision Toolbox"* Application in MATLAB**

----


1. Download ***Computer Vision Toolbox*** in MATLAB.

![img3](https://user-images.githubusercontent.com/84509483/226327538-cb410359-6337-4030-b6fd-83042b1db028.PNG)

---


2. Open the ***Camera Calibrator*** applicaiton.

![img2](https://user-images.githubusercontent.com/84509483/226327602-6d01d8c2-bf21-4fb0-812c-c6438fec07ba.PNG)

---


3. Download images for camera calibration. [(link)](https://github.com/ykkimhgu/DLIP-src/blob/main/Tutorial_Calibration/camera_calibration_images.zip)

---

4. Load images to camera calibrator app.

![img](https://user-images.githubusercontent.com/84509483/226327653-216ad6ed-34ea-4fab-bd60-98499c6e18c7.PNG)

---


5. Select Pattern / checkerboard square size / image distortion

![img4](https://user-images.githubusercontent.com/84509483/226327686-7ee6cf2d-e079-4b28-9e30-1db0482f04a9.PNG)

---


6. Click ***Calibrate*** button.

![img5](https://user-images.githubusercontent.com/84509483/226327718-35316e83-78bc-4d68-aa43-ee61d96d16ac.PNG)

---

7. Export Parameters to workspace / Save ***cameraParams*** in your workspace named as **"cameraParams.mat"**

![img6](https://user-images.githubusercontent.com/84509483/226327732-b066f4a1-fc5e-4d07-8d66-f5ddfafb2acb.PNG)

---


8. Download test code([link](https://github.com/ykkimhgu/DLIP-src/blob/main/Tutorial_Calibration/DLIP_Tutorial_Calibration_GetUndistortedImg.m)) and Run the code

![img7](https://user-images.githubusercontent.com/84509483/226327756-702956a0-f1d7-4098-a7fb-2b149f31df37.PNG)

---


9. Apply ***cameraParams*** to cpp test code([link](https://github.com/ykkimhgu/DLIP-src/blob/main/Tutorial_Calibration/ShowUndistorted.cpp))

![img8](https://user-images.githubusercontent.com/84509483/226327795-2cf5e1fc-e856-4a53-8c23-625d71ad43ff.PNG)

---

