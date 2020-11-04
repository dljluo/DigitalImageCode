/* ��ϰ6-2 ��ת������ */
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    cv::Mat srcMat;
    cv::Mat dstMat;

    srcMat = cv::imread("D:\\Programming\\CC++\\DigitalImageCode\\coin.jpg", 1);
    if(srcMat.empty()) return -1;

    //��ת-40�㣬���ųߴ�Ϊ
    float angle = -10.0, scale = 1;
    //��ת����Ϊͼ������
    cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
    //��ñ任����
    const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);

    cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

    cv::imshow("src", srcMat);
    cv::imshow("dst", dstMat);
    cv::waitKey(0);

    return 0;
}