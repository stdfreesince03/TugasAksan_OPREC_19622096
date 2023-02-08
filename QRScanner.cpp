

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/core/utils/logger.hpp>
#include <opencv2/opencv.hpp>
#include <windows.h>
#include <shellapi.h>


using namespace cv;
using namespace std;



int main(){
        cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);

        String imagePath = "Resources/KSMFull.jpg";
        Mat image, box, resq, croppedImage;

        image = imread(imagePath);
        croppedImage = imread(imagePath,COLOR_BGR2GRAY);
        resize(image, image, Size(1000,1000));
    
    
        QRCodeDetector qrDet = QRCodeDetector::QRCodeDetector();
    
  
        string data = qrDet.detectAndDecode(image, box, resq);
        box.convertTo(box,CV_64FC3);

        
        if (data.length() > 0) {
           std::cout << "Data after decoding: " << data << std::endl;
        }
        else {
            std::cout << "QR Code not detected" << std::endl;
        }

        
        int init = 0;
        for (int i = 0; i < box.cols; i++) {
            Point pt1(box.at<double>(0, init), box.at<double>(0, init + 1));
            init += 2;
            if (i == box.cols - 1) {
                init = 0;
            }
            Point pt2(box.at<double>(0, init), box.at<double>(0, init + 1));
            line(image, pt1, pt2, Scalar(255, 0, 0), 3);
        }

        croppedImage = image(Range(box.at<double>(0, 3), box.at<double>(0, 5)),Range(box.at<double>(0,0), box.at<double>(0,2)));
        resize(image, image, Size(800,800), 0, 0, 0);
      
        string op = string("start ").append(data);
        system(op.c_str());

        imshow("Detected", image);
        imshow("Detected QR code", croppedImage);
       
        waitKey(0);

        return 0;
 

    }



    
  

   

   
    
  



