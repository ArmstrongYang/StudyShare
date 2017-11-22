#include <string>

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"


using namespace cv;
using namespace std;

int contours(int argc, char** argv)
{
	string imagePath = "images/cells.png";
	Mat cellImage = imread(imagePath);
	// to gray
	Mat result1d;
	cv::cvtColor(cellImage, result1d, CV_BGR2GRAY);
	// threshold
	cv::threshold(result1d, result1d, 128, 255, cv::THRESH_BINARY);
	imshow("cellImage", cellImage);
	imshow("result1d", result1d);

	vector<vector<Point>> contours;
	// find contours and got contours sum
	cv::findContours(result1d, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	Mat result(result1d.size(), CV_8U, cv::Scalar(0));

	cv::drawContours(result, contours, -1, cv::Scalar(0), 2);
	cv::namedWindow("contours");
	cv::imshow("contours", result);
	//int ctsSum = contours.size();

	//Mat resultImage = Mat::zeros(result1d.size(), CV_8U);
	//drawContours(resultImage, contours, -1, Scalar(255, 0, 255));
	//// draw all contours // draw polygon in cell finded and count polygon-edges to count cell num
	//for (int i = 0; i<ctsSum; i++) {
	//	cv::drawContours(cellImage, contours, i, cv::Scalar(0, 255, 0), 2);
	//}
	waitKey(0);
	return 0;
}