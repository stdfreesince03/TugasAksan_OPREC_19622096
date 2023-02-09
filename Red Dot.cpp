

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utils/logger.hpp>

using namespace cv;
using namespace std;



int main()

{
    cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);

    

    String path = "Resources/Red Dot.mp4";
    VideoCapture cap(path);

    Mat img;

   

    while (true) {
        cap.read(img);
        resize(img, img, Size(1000, 800),INTER_NEAREST_EXACT);


        Mat hsv;

        cvtColor(img,hsv, COLOR_BGR2HSV);

        Mat1b mask1, mask2;
        inRange(hsv, Scalar(0, 70, 50), Scalar(10, 255, 255), mask1);
        inRange(hsv, Scalar(170, 70, 50), Scalar(180, 255, 255), mask2);
        Mat1b mask = mask1 | mask2;
       
        


        Mat Points;
        findNonZero(mask, Points);
        Rect Min_Rect = boundingRect(Points);

        rectangle(img, Min_Rect.tl(), Min_Rect.br(),Scalar(88,7,97), 4);
        imshow("Image detect", img);
    

        char key = waitKey(1);
        if (key == 'q') {
            break;
        }
    }

   
   
    return 0;
}



