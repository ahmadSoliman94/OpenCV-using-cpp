#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;



////////////////////////// Morphological operations in OpenCV ////////////////////////

// main function
int main() {

    // read image
    Mat img = imread("./img.png", IMREAD_COLOR );

    // check for image
    if (img.empty()) {
        printf("Image not found\n");
        return -1; // -1 means unsuccessful   
    }

    // create Mat objects
    Mat erodeMat, dilateMate; 
      
    Mat elemntKernel = getStructuringElement(MORPH_RECT, Size(10,10), Point(-1,-1)); // MORPH_RECT is rectangular structuring element, Size(3,3) is size of the structuring element, Point(-1,-1) is position of the anchor within the element. The default value (-1, -1) means that the anchor is at the element center.


    // apply erosion operation: is used to remove noise from an image. It erodes away the boundaries of foreground object.

    /*
    parameters:
    src: input image
    dst: output image
    kernel: structuring element used for erosion. If element = Mat(), a 3 x 3 rectangular structuring element is used. Kernel can be created using getStructuringElement().
    anchor: position of the anchor within the element. The default value (-1, -1) means that the anchor is at the element center.
    iterations: number of times erosion is applied.
    borderType: pixel extrapolation method.
    borderValue: border value in case of a constant border. 
    */

    erode(img, erodeMat, elemntKernel, Point(-1,-1), 1); // 1 is number of times erosion is applied.


    // apply dilation opreation: is used to remove noise from an image. It increases the object area.

    /*
    parameters:
    src: input image
    dst: output image
    kernel: structuring element used for dilation. If element = Mat(), a 3 x 3 rectangular structuring element is used. Kernel can be created using getStructuringElement().
    anchor: position of the anchor within the element. The default value (-1, -1) means that the anchor is at the element center.
    iterations: number of times dilation is applied.
    borderType: pixel extrapolation method.
    borderValue: border value in case of a constant border. 
    */

    dilate(img, dilateMate, elemntKernel, Point(-1,-1), 1); // 1 is number of times dilation is applied.

    // show image
    imshow("Original Image", img);
    imshow("Eroded Image", erodeMat); 
    imshow("Dilated Image", dilateMate); 
    waitKey(0);


    return 0; // 0 means successful termination 

}