
#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;

int main() {
    Mat img = imread("./tree.jpg", IMREAD_GRAYSCALE);
    if (img.empty()) {
        printf("Image load failed!\n");
        return -1;
    }
    
    imshow("image", img);
    waitKey(0); // 0: wait forever

    return 0;

}