/* 练习6-3 仿射变换 */
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    cv::Mat dstMat;
    cv::Mat srcMat = cv::imread("D:\\Programming\\CC++\\DigitalImageCode\\2.jpg", 1);
    if(srcMat.empty()) return -1;

    //变换前三点坐标
    const cv::Point2f src_pt[] = {
                                    cv::Point2f(200,200),
                                    cv::Point2f(250,200),
                                    cv::Point2f(200,100) };
    //变换后三点坐标
    const cv::Point2f dst_pt[] = {
                                    cv::Point2f(300,100),
                                    cv::Point2f(300, 50),
                                    cv::Point2f(200,100) };
    //计算仿射矩阵
    const cv::Mat affine_matrix = cv::getAffineTransform(src_pt, dst_pt);

    cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

    cv::imshow("src", srcMat);
    cv::imshow("dst", dstMat);
    cv::waitKey(0);

    return 0;
}
