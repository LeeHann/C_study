#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
using namespace cv;
using namespace std;

int exam1()
{
    Mat img = imread("../../res/Lenna.png", IMREAD_COLOR);
    if (img.empty())
    {
        printf("image load error \n");
        return 1;
    }

    imshow("Display", img);
    waitKey(0);

    return 0;
}

int exam2_cam()
{
    Mat img_color;

    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        printf("camera open error");
        return 1;
    }

    while (1)
    {
        cap.read(img_color);

        imshow("Color", img_color);
        if (waitKey(25) >= 0)
        {
            break;
        }
    }
    imwrite("capture.png", img_color);

    return 0;
}

int main() 
{

    return exam2_cam();
}