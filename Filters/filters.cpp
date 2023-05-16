
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;



//////////////////////// Filters in OpenCV ////////////////////////


// main function
int main() {

    // read image
    Mat img = imread("./person.jpg", IMREAD_COLOR );

    // check for image
    if (img.empty()) {
        printf("Image not found\n");
        return -1; // -1 means unsuccessful   
    }

    // create Mat objects
    Mat bilateral, gaussian, median; 


    // apply bilateral filter: preserves edges.

    /*
    parameters:
    src: input image
    dst: output image
    d: diameter of each pixel neighborhood that is used during filtering. Color images uses small d because the difference between colors of neighbor pixels is considered while filtering. 
    sigmaColor: means that the larger the value of the parameter, the farther colors within the pixel neighborhood will be mixed together.
    sigmaSpace: thats means that the larger the value of the parameter, the farther pixels will influence each other as long as their colors are close enough. 
    */

    bilateralFilter(img, bilateral, 15, 95, 45); // 15 is diameter of each pixel neighborhood, 95 is sigmaColor, 45 is sigmaSpace


    // apply gaussian filter: blurs image

    /* 
    parameters:
    src: input image
    dst: output image
    ksize: Gaussian kernel size. ksize.width and ksize.height can differ but they both must be positive and odd. Or, they can be zero’s and then they are computed from sigma.
    sigmaX: Gaussian kernel standard deviation in X direction.
    sigmaY: Gaussian kernel standard deviation in Y direction. If sigmaY is zero, it is set to be equal to sigmaX. If both sigmas are zeros, they are computed from ksize.width and ksize.height, respectively. 
    */


    GaussianBlur(img, gaussian, Size(15,15), 0, 0); // 5 is kernel size, 0 is sigmaX and sigmaY


    // apply median filter: is use to remove noise from an image

    /* 
    parameters:
    src: input image
    dst: output image
    ksize: aperture linear size; it must be odd and greater than 1, for example: 3, 5, 7 ...
    */

    medianBlur(img, median, 15); // 5 is aperture linear size


    // show image
    imshow("Original Image", img);
    imshow("Bilateral Filter", bilateral);
    imshow("Gaussian Filter", gaussian);
    imshow("Median Filter", median);
    waitKey(0);

    return 0; // 0 means successful


}