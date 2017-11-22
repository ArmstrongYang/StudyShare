#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
int video(int, char**)
{
	VideoCapture cap(0);
	if (!cap.isOpened()) return -1;
	Mat frame, edges;
	namedWindow("edges", 1);
	for (;;)
	{
		cap >> frame;
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		imshow("frame", frame);
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}