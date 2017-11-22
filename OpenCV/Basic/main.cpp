#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
int main()
{
	cv::Mat image = cv::imread("images/cells.png", 0);
	cv::namedWindow("image");
	cv::imshow("image", image);
	cv::Mat binary;
	cv::threshold(image, binary, 120, 255, cv::THRESH_BINARY);	//THRESH_BINARY_INV
	cv::namedWindow("binary");
	cv::imshow("binary", binary);
	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(binary, contours, -1, cv::CHAIN_APPROX_NONE);
	cv::Mat result(image.size(), CV_8U, cv::Scalar(128));
	cv::drawContours(image, contours, -1, cv::Scalar(200), 2);
	cv::namedWindow("contours");
	cv::imshow("contours", image);
	cv::waitKey(0);
	return 0;
}