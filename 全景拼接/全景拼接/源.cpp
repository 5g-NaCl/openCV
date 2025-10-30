#include<opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main() {
	string filePath = "C:/opencv_pic/Æ´½Ó";
	vector<string>fileNames;
	vector<Mat>imgs;

	glob(filePath, fileNames);
	for (auto fileName : fileNames) {
		Mat img = imread(fileName);
		if (img.empty()) {
			continue;
		}
		imgs.push_back(img);
	}
	Mat pano;
	Ptr < Stitcher >stitcher= Stitcher::create(Stitcher::PANORAMA);
	Stitcher::Status status = stitcher->stitch(imgs, pano);
	if (status != Stitcher::OK) {
		cout << "failed" << endl;
		return -1;
	}
	return 0;

}