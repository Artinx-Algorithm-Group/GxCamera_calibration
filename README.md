# GxCamera_calibration    
(This file is to be finish later ... )    





## Environment:
OpenCV4.4.0 + (Daheng Galaxy Linux)MDK



## Build & Run:



### If in terminal:


```
cd build

cmake ..

make
```

And You will find the executable in ${workspaceFolder}/exe



### If in vscode:  

We have already complete the task.json for you

Run Task : build (to build all)

Run Task : main1 (to run main1_initboard) 

Run Task : main2 (to run main2_takeImgSave)

Run Task : main3 (to run mian3_calibration)

Run Task : clear binary (to clear build files)

Run Task : clear exe (to clear output executable file)



## Run Instruction

You are strongly recommended to run this program with default param value, that is, not to give optional value in command lines.

#### main1_initboard:

You can run with param , for eg, to run main1

```
./main1_initboard -w=12 -h=6 -l=80 -path=../img/chessboard.jpg
```

But you are not recommended to modified these params since you have to change the relative value of params in the default.xml if you change the value in command lines:

```xml
  <!-- Number of inner corners per a item row and column. (square, circle) -->
  <BoardSize_Width> 9</BoardSize_Width>
  <BoardSize_Height>7</BoardSize_Height>

  <!-- The size of a square in some user defined metric system (pixel, millimeter)-->
  <Square_Size>25</Square_Size>

  <!-- The input to use for calibration. 
		To use an input camera -> give the ID of the camera, like "1"
		To use an input video  -> give the path of the input video, like "/tmp/x.avi"
		To use an image list   -> give the path to the XML or YAML file containing the    list of the images, like "/tmp/circles_list.xml"
  -->
  <Input>"../img/images.xml"</Input>

   <!-- The name of the output log file. -->
  <Write_outputFileName>"../img/out_camera_data.xml"</Write_outputFileName>

```















