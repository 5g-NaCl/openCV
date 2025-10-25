#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
void cv_show(Mat img) {
	imshow("img", img);
	waitKey(0);
}
int main() {
	Mat img(512, 512, CV_8UC3, Scalar(0, 0, 0));//CV����ǰ׺ 8U��ʾ8λ�޷���0~255 C3 3��ͨ��
	
	Point start_point(0, 0);
	Point end_point(img.cols - 1, img.rows - 1);

	line(img, start_point, end_point, Scalar(255, 0, 0), 2);//Scalar ��ʾ��ɫBRG
	rectangle(img, Point(100, 100), Point(400, 400), Scalar(0, 255, 0), 5);
	circle(img, Point(300, 300), 200, Scalar(0, 0, 255), 10);
	putText(img, "hello,opencv", Point(50, 250), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(255, 255, 0), 2, LINE_AA);
	//���룬���ͼ��  ��ʵ�㣬���壬������� ��ɫ�����������
	cv_show(img);

	Mat img2(img.cols,img.rows,img.type(),Scalar(0));

	Mat img3;
	img3.create(img.size(), img.type());
	cv_show(img3);
	img3 = Scalar(0, 255, 0);
	cv_show(img3);
}