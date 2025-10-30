#include<opencv2\opencv.hpp>
#include<cmath>
using namespace cv;
using namespace std;
void TAGC_Enhancement(const cv::Mat& src, cv::Mat& dst) {
	CV_Assert(src.type() == CV_8UC3);//确保3通道
	Mat srcFloat;
	src.convertTo(srcFloat, CV_32FC3, 1.0 / 255.0);//转化浮点并归一化到[0-1]
	dst.create(src.size(), src.type());

	for (int y = 0; y < srcFloat.rows; y++) {
		const float* linePS = srcFloat.ptr<float>(y);
		uchar* linePD = dst.ptr<uchar>(y);
		for (int x = 0; x < srcFloat.cols; x++) {
			float blue = linePS[0];
			float green = linePS[1];
			float red = linePS[2];
			float L = 0.2126f * red + 0.75f * green + 0.0722f * blue;
			float A = (blue + green + red) / 3.f;
			float Gamma = 5.0f + (0.5f - L) * (1.0f - A) - 2.0f * L;

			linePD[0] = cvRound(std::pow(blue, 2.0f / Gamma) * 255.0f);
			linePD[1] = cvRound(std::pow(green, 2.0f / Gamma) * 255.0f);
			linePD[2] = cvRound(std::pow(red, 2.0f / Gamma) * 255.0f);
			linePS += 3;
			linePD += 3;
		}
	}
}

int main() {
	Mat src = imread("屏幕截图 2025-10-20 201912.png");
	if (src.empty()) {
		cout<<"Failed"<<endl;
	}
	Mat dst;
	TAGC_Enhancement(src, dst);
}