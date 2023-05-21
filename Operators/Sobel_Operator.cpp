
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;



// ======================================= Sobel Operator =======================================


// main function
int main() {


    // read image
    Mat img = imread("./images/img1.jpg", IMREAD_COLOR );

    namedWindow("Input", WINDOW_NORMAL); // create window to display image
    namedWindow("Output", WINDOW_NORMAL);

    Mat outputImg;

    int dx = 1, dy = 1; // order of derivative x and y
    int sobelSize = 3; // size of kernel
    int scaleFactor = 1; // optional scale factor
    int delta = 0; // optional delta value



    // apply sobel operator

    /*
    parameters:
    src: input image
    dst: output image
    ddepth: depth of output image
    dx: order of derivative x
    dy: order of derivative y
    ksize: size of kernel
    scale: optional scale factor for the computed derivative values; by default, no scaling is applied (see getDerivKernels for details)
    delta: optional delta value that is added to the results prior to storing them in dst.
    borderType: pixel extrapolation method
    */ 
    Sobel(img, outputImg, CV_8U, dx, dy, sobelSize, scaleFactor, delta); // 1 is xorder, 1 is yorder. CV_8U is depth of output image







    // show image
    imshow("iNPUT", img);
    imshow("Output", outputImg);
    waitKey(0);

    return 0; // 0 means successful
}