#ifndef _H2_TAKEIMGS_HPP_
#define _H2_TAKEIMGS_HPP_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <sstream>
#include "GxCamera.hpp"

using namespace std;




/// Status
#define TAKE_IMG_STATUS_TRUE_ 0
#define TAKE_IMG_STATUS_FALSE_ -1

/// Camera properties
#define EXPOSURE_TIME_VALUE 5000
#define FRAME_RATE 100

/// To be modified
#define TAKE_IMG_MIN_COUNT_ 3
#define TAKE_IMG_XML_FILENAME_ "../img/images.xml"



class TakeImg
{
private:

    vector<string> strVec;
  

public:

    TakeImg(){this->count = 0;}
    ~TakeImg(){}

    /// take img loop
    int TakeImgLoop();

    /// save xml
    int SaveXml();

public:
    int count;
 
};





/// take img loop
int TakeImg::TakeImgLoop()
{
    cv::Mat frame;

    GxCamera *camera = new GxCamera();
    camera->camStatus = GX_STATUS_SUCCESS;

    camera->camStatus = camera->CameraInitOps();
    GX_CHECK(camera->camStatus);

    /// Can set alternative properties here
    camera->camStatus = camera->SetExposureTime(EXPOSURE_TIME_VALUE);
    camera->camStatus = camera->SetFrameRate(FRAME_RATE);
    
    /// StreamOn
    camera->camStatus = camera->StreamOn();
    GX_CHECK(camera->camStatus);


    char flag = 'a';
    stringstream ss;
    string tempstr;
    cv::namedWindow("show frame",cv::WINDOW_AUTOSIZE);
    while(true)
    {
        camera->GetColorImg(frame);
 
        cv::imshow("show frame",frame);
        flag = cv::waitKey(30);

        if(flag == 't')
        {
            this->count++;
            ss << "../img/" << "img" << count << ".jpg\0";
            tempstr = ss.str();
            strVec.push_back(tempstr);
            cv::imwrite(tempstr,frame);
            cout << "Success write " << tempstr << endl;
        }
        else if(flag == 'q')
        {
            if(this->count>=TAKE_IMG_MIN_COUNT_)
            {
                return TAKE_IMG_STATUS_TRUE_;
            }
            else{
                cout << "Failed. You should take at least "<<TAKE_IMG_MIN_COUNT_<<" imgs."<<endl;
                return TAKE_IMG_STATUS_FALSE_;
            }
        }
        ss.str("");
    }


     /// StreamOff
    camera->camStatus = camera->StreamOff();
    GX_CHECK(camera->camStatus);

    /// Close camera
    camera->camStatus = camera->CameraCloseOps();
    GX_CHECK(camera->camStatus);
    delete camera;
    camera = NULL;


    return TAKE_IMG_STATUS_TRUE_;
}

/// save xml
int TakeImg::SaveXml()
{
    cv::FileStorage fs;

    fs.open(TAKE_IMG_XML_FILENAME_,cv::FileStorage::WRITE);

    fs << "strVector" << "[";

    for(int a = 0; a < this->count; a++)
    {
        
        // const char* tempChar = this->strVec[a].c_str();
        // int len = strVec[a].length();
        // const char *tempChar = this->strVec[a].c_str();
        // fs << tempChar;
        fs << this->strVec[a];
    }
    
    fs << "]";
    fs.release();
    return TAKE_IMG_STATUS_TRUE_;
}


#endif