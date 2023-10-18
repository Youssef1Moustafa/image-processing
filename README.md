# image-processing
toolbox about Digital Image Processing by c++ programming language 

USER MANUAL:-
-	Download visual studio 2022 community free version from this link 
-	Download Visual Studio Tools - Install Free for Windows, Mac, Linux (microsoft.com)
-	Download open cv library from this link 

opencv library:-
-       https://sourceforge.net

version
-       OpenCV 4.8.1 has been released.

:hammer_and_wrench: Change log is [here](https://github.com/opencv/opencv/wiki/ChangeLog#version481).

SHA256 sum for packages:

    a8bfe53cf9d7fa94ed5d85d61cf028348a6a1268b8027c9bc95ca96edd90ba13  opencv-4.8.1-android-sdk.zip
    0689312a9de439757618a412b266dc5ee75d2e32aefa9eac32c3f808ade06331  opencv-4.8.1-ios-framework.zip
    037dd1c5c172237b0a00ee822684e5ac453028e1933111a2c547b62061f8b7e4  opencv-4.8.1-windows.exe

read by visual studio:-
Put the opencv folder in the “E:\” partition 

, E:\open cv\opencv\build\x64\vc15\bin, and copy the .dll files. 

Go to: C:\Windows\System32, and paste,
Then from visual studio download individual components 

, Install it 

, then 
Download the project folder then put in the directory:
E:\open cv
Then open the visual studio and open solution “other toolbox.sln”.

Add Opencv files to the project:-

1. Configuration -> all configuration and platform -> x64

2. C/C++ -> General 
Additional include directory -> write the path of the include folder on your 
device. For example “E:\opencv\build\include”.

3. Linker -> General
Additional library directories write the path of the lib folder on your 
device. for example “E:\opencv\build\x64\vc15\lib”.

4. Configuration -> Debug and platform -> x64 
Linker -> input 
Additional dependencies -> write “opencv_world341d.lib”.

5. Configuration -> Release and platform -> x64 
Linker -> input
Additional dependencies -> write “opencv_world341.lib”

----------All Setup----------
