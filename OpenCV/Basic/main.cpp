#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>


using namespace cv;
using namespace std;

int contoursShow()
{
	cv::Mat image = cv::imread("images/box.png", 0);
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




static void help()
{
	cout
		<< "\nThis program illustrates the use of findContours and drawContours\n"
		<< "The original image is put up along with the image of drawn contours\n"
		<< "Usage:\n"
		<< "./contours2\n"
		<< "\nA trackbar is put up which controls the contour level from -3 to 3\n"
		<< endl;
}
const int w = 500;
int levels = 3;
vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
static void on_trackbar(int, void*)
{
	Mat cnt_img = Mat::zeros(w, w, CV_8UC3);
	int _levels = levels - 3;
	drawContours(cnt_img, contours, _levels <= 0 ? 3 : -1, Scalar(128, 255, 255),
		3, LINE_AA, hierarchy, std::abs(_levels));
	imshow("contours", cnt_img);
}
int contours_face(int argc, char**)
{
	Mat img = Mat::zeros(w, w, CV_8UC1);
	if (argc > 1)
	{
		help();
		return -1;
	}
	//Draw 6 faces
	for (int i = 0; i < 6; i++)
	{
		int dx = (i % 2) * 250 - 30;
		int dy = (i / 2) * 150;
		const Scalar white = Scalar(255);
		const Scalar black = Scalar(0);
		if (i == 0)
		{
			for (int j = 0; j <= 10; j++)
			{
				double angle = (j + 5)*CV_PI / 21;
				line(img, Point(cvRound(dx + 100 + j * 10 - 80 * cos(angle)),
					cvRound(dy + 100 - 90 * sin(angle))),
					Point(cvRound(dx + 100 + j * 10 - 30 * cos(angle)),
						cvRound(dy + 100 - 30 * sin(angle))), white, 1, 8, 0);
			}
		}
		ellipse(img, Point(dx + 150, dy + 100), Size(100, 70), 0, 0, 360, white, -1, 8, 0);
		ellipse(img, Point(dx + 115, dy + 70), Size(30, 20), 0, 0, 360, black, -1, 8, 0);
		ellipse(img, Point(dx + 185, dy + 70), Size(30, 20), 0, 0, 360, black, -1, 8, 0);
		ellipse(img, Point(dx + 115, dy + 70), Size(15, 15), 0, 0, 360, white, -1, 8, 0);
		ellipse(img, Point(dx + 185, dy + 70), Size(15, 15), 0, 0, 360, white, -1, 8, 0);
		ellipse(img, Point(dx + 115, dy + 70), Size(5, 5), 0, 0, 360, black, -1, 8, 0);
		ellipse(img, Point(dx + 185, dy + 70), Size(5, 5), 0, 0, 360, black, -1, 8, 0);
		ellipse(img, Point(dx + 150, dy + 100), Size(10, 5), 0, 0, 360, black, -1, 8, 0);
		ellipse(img, Point(dx + 150, dy + 150), Size(40, 10), 0, 0, 360, black, -1, 8, 0);
		ellipse(img, Point(dx + 27, dy + 100), Size(20, 35), 0, 0, 360, white, -1, 8, 0);
		ellipse(img, Point(dx + 273, dy + 100), Size(20, 35), 0, 0, 360, white, -1, 8, 0);
	}
	//show the faces
	namedWindow("image", 1);
	imshow("image", img);
	//Extract the contours so that
	vector<vector<Point> > contours0;
	findContours(img, contours0, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	contours.resize(contours0.size());
	for (size_t k = 0; k < contours0.size(); k++)
		approxPolyDP(Mat(contours0[k]), contours[k], 3, true);
	namedWindow("contours", 1);
	createTrackbar("levels+3", "contours", &levels, 7, on_trackbar);
	on_trackbar(0, 0);
	waitKey();
	return 0;
}

int circle_stone()
{
	Mat imageSource = imread("images/stone.png", 0);
	imshow("Source Image", imageSource);
	Mat image;
	blur(imageSource, image, Size(3, 3));
	threshold(image, image, 0, 255, CV_THRESH_OTSU);
	threshold(image, image, 0, 255, THRESH_BINARY_INV);
	imshow("Threshold Image", image);

	//Ѱ�����������
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE, Point());

	Mat imageContours = Mat::zeros(image.size(), CV_8UC1);	//��С��Ӿ��λ���
	Mat imageContours1 = Mat::zeros(image.size(), CV_8UC1); //��С���Բ����
	for (int i = 0; i<contours.size(); i++)
	{
		//��������
		drawContours(imageContours, contours, i, Scalar(255), 1, 8, hierarchy);
		drawContours(imageContours1, contours, i, Scalar(255), 1, 8, hierarchy);


		//������������С������
		RotatedRect rect = minAreaRect(contours[i]);
		Point2f P[4];
		rect.points(P);
		for (int j = 0; j <= 3; j++)
		{
			line(imageContours, P[j], P[(j + 1) % 4], Scalar(255), 2);
		}

		//������������С���Բ
		Point2f center; float radius;
		minEnclosingCircle(contours[i], center, radius);
		circle(imageContours1, center, radius, Scalar(255), 2);

	}
	imshow("MinAreaRect", imageContours);
	imshow("MinAreaCircle", imageContours1);
	waitKey(0);
	return 0;
}
typedef vector<cv::Point> VP;
VP FindBigestContour(Mat src) {
	int imax = 0; //����������������
	int imaxcontour = -1; //������������Ĵ�С
	std::vector<std::vector<cv::Point>>contours;
	findContours(src, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
	for (int i = 0; i<contours.size(); i++) {
		int itmp = contourArea(contours[i]);//������õ���������С
		if (imaxcontour < itmp) {
			imax = i;
			imaxcontour = itmp;
		}
	}
	return contours[imax];
}
int find_maxCircle()
{
	Mat src = imread("images/circle_one.png");
	Mat temp;
	cvtColor(src, temp, COLOR_BGR2GRAY);
	threshold(temp, temp, 100, 255, THRESH_OTSU);
	imshow("src", temp);
	//Ѱ���������
	VP VPResult = FindBigestContour(temp);
	//Ѱ���������Բ
	int dist = 0;
	int maxdist = 0;
	Point center;
	for (int i = 0; i<src.cols; i++)
	{
		for (int j = 0; j<src.rows; j++)
		{
			dist = pointPolygonTest(VPResult, cv::Point(i, j), true);
			if (dist>maxdist)
			{
				maxdist = dist;
				center = cv::Point(i, j);
			}
		}
	}
	//���ƽ��
	circle(src, center, maxdist, Scalar(0, 0, 255));
	imshow("dst", src);
	waitKey();
	return 0;
}

int main(int argc, char** argv)
{
	//contoursShow();
	//circle_stone();
	find_maxCircle();
}