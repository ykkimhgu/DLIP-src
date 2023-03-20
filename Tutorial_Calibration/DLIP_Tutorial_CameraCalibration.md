# Tutorial: Camera Calibration



## Tutorial

DLIP Tutorial for Camera Calibration using MATLAB



**Using *"Computer Vision Toolbox"* Application in MATLAB**

For the camera calibration tutorial, we will use MATLAB.

1. Download ***Computer Vision Toolbox*** in MATLAB.

![image-20230320195018734](C:\Users\Taewoong\AppData\Roaming\Typora\typora-user-images\image-20230320195018734.png)

2. Open the ***Camera Calibrator*** applicaiton.

![image-20230320195220445](C:\Users\Taewoong\AppData\Roaming\Typora\typora-user-images\image-20230320195220445.png)



3. Download images for camera calibration. [(link)](https://github.com/ykkimhgu/DLIP-src/blob/main/Tutorial_Calibration/camera_calibration_images.zip)

4. Load images to camera calibrator app.

![image-20230320200030785](C:\Users\Taewoong\AppData\Roaming\Typora\typora-user-images\image-20230320200030785.png)

5. Select Pattern / checkerboard square size / image distortion

![image-20230320200443667](C:\Users\Taewoong\AppData\Roaming\Typora\typora-user-images\image-20230320200443667.png)

6. Click ***Calibrate*** button.

![image-20230320200846621](C:\Users\Taewoong\AppData\Roaming\Typora\typora-user-images\image-20230320200846621.png)

7. Export Parameters to workspace / Save ***cameraParams*** in your workspace named as **"cameraParams.mat"**

![image-20230320201310007](C:\Users\Taewoong\AppData\Roaming\Typora\typora-user-images\image-20230320201310007.png)

8. Download test code([link](https://github.com/ykkimhgu/DLIP-src/blob/main/Tutorial_Calibration/DLIP_Tutorial_Calibration_GetUndistortedImg.m)) and Run the code

![image-20230320201857051](C:\Users\Taewoong\AppData\Roaming\Typora\typora-user-images\image-20230320201857051.png)

9. Apply ***cameraParams*** to cpp test code([link](https://github.com/ykkimhgu/DLIP-src/blob/main/Tutorial_Calibration/ShowUndistorted.cpp))

![image-20230320202754881](C:\Users\Taewoong\AppData\Roaming\Typora\typora-user-images\image-20230320202754881.png)