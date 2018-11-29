
#include "wordParser.h"
#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


// 각 색상에 대한 Vec3b를 미리 설정한다
//Vec3b로 나타내면 B, G, R순이다
#define Vec3bRed Vec3b(0, 0, 255)
#define Vec3bGreen Vec3b(0, 255, 0)
#define Vec3bBlue Vec3b(255, 0, 0)
#define Vec3bBlack Vec3b(0, 0, 0)
#define Vec3bYellow Vec3b(0, 255, 255)

const static int IntBlack = 0;
const static int IntRed = 1;
const static int IntGreen = 2;
const static int IntYellow = 3;
const static int IntBlue = 4;

// 파일의 사이즈를 정한다
const static int inputXsize = 140;
const static int inputYsize = 140;

// 지점을 정의해둔다
const static int pointRecogX = 20;
const static int pointRecogY = 20;

// 건너뛸 스텝을 지정한다
const static int stepPixel = 20;

void color_one_box(Mat img, int x, int y, int colorNum) { // 지정된 x, y로부터 20 x 20칸을 칠한다
	Vec3b color;
	switch (colorNum) {
	case IntRed:
		color = Vec3bRed;
		break;
	case IntGreen:
		color = Vec3bGreen;
		break;
	case IntBlue:
		color = Vec3bBlue;
		break;
	case IntBlack:
		color = Vec3bBlack;
		break;
	case IntYellow:
		color = Vec3bYellow;
		break;
	default:
		color = Vec3bBlack;
		break;
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			img.at<Vec3b>(y + i, x + j) = color;
		}
	}
}

void color_three_box(Mat img, int firstX, int firstY, int firstColor,
	int secondX, int secondY, int secondColor,
	int thirdX, int thirdY, int thirdColor) {

	color_one_box(img, firstX, firstY, firstColor);
	color_one_box(img, secondX, secondY, secondColor);
	color_one_box(img, thirdX, thirdY, thirdColor);
}

bool color_marker(Mat img, char* word) {
	string parseResult;
	// 마커 인식 포인트에 파랑색칠
	color_one_box(img, pointRecogX, pointRecogY, IntBlue);

	// 첫번째 글자
	parseResult = wordParser(word[0]);
	if (parseResult == "999") return false;
	color_three_box(img,
		pointRecogX + stepPixel * 1, pointRecogY + stepPixel * 0, parseResult[0] - '0',
		pointRecogX + stepPixel * 2, pointRecogY + stepPixel * 0, parseResult[1] - '0',
		pointRecogX + stepPixel * 3, pointRecogY + stepPixel * 0, parseResult[2] - '0');
	// 두번째 글자
	parseResult = wordParser(word[1]);
	if (parseResult == "999") return false;
	color_three_box(img,
		pointRecogX + stepPixel * 4, pointRecogY + stepPixel * 0, parseResult[0] - '0',
		pointRecogX + stepPixel * 0, pointRecogY + stepPixel * 1, parseResult[1] - '0',
		pointRecogX + stepPixel * 1, pointRecogY + stepPixel * 1, parseResult[2] - '0');
	// 세번째 글자
	parseResult = wordParser(word[2]);
	if (parseResult == "999") return false;
	color_three_box(img,
		pointRecogX + stepPixel * 2, pointRecogY + stepPixel * 1, parseResult[0] - '0',
		pointRecogX + stepPixel * 3, pointRecogY + stepPixel * 1, parseResult[1] - '0',
		pointRecogX + stepPixel * 4, pointRecogY + stepPixel * 1, parseResult[2] - '0');
	// 네번째 글자
	parseResult = wordParser(word[3]);
	if (parseResult == "999") return false;
	color_three_box(img,
		pointRecogX + stepPixel * 0, pointRecogY + stepPixel * 2, parseResult[0] - '0',
		pointRecogX + stepPixel * 1, pointRecogY + stepPixel * 2, parseResult[1] - '0',
		pointRecogX + stepPixel * 2, pointRecogY + stepPixel * 2, parseResult[2] - '0');
	// 다섯번째 글자
	parseResult = wordParser(word[4]);
	if (parseResult == "999") return false;
	color_three_box(img,
		pointRecogX + stepPixel * 3, pointRecogY + stepPixel * 2, parseResult[0] - '0',
		pointRecogX + stepPixel * 4, pointRecogY + stepPixel * 2, parseResult[1] - '0',
		pointRecogX + stepPixel * 0, pointRecogY + stepPixel * 3, parseResult[2] - '0');
	// 여섯번째 글자
	parseResult = wordParser(word[5]);
	if (parseResult == "999") return false;
	color_three_box(img,
		pointRecogX + stepPixel * 1, pointRecogY + stepPixel * 3, parseResult[0] - '0',
		pointRecogX + stepPixel * 2, pointRecogY + stepPixel * 3, parseResult[1] - '0',
		pointRecogX + stepPixel * 3, pointRecogY + stepPixel * 3, parseResult[2] - '0');
	// 일곱번째 글자
	parseResult = wordParser(word[6]);
	if (parseResult == "999") return false;
	color_three_box(img,
		pointRecogX + stepPixel * 4, pointRecogY + stepPixel * 3, parseResult[0] - '0',
		pointRecogX + stepPixel * 0, pointRecogY + stepPixel * 4, parseResult[1] - '0',
		pointRecogX + stepPixel * 1, pointRecogY + stepPixel * 4, parseResult[2] - '0');
	// 여덟번째 글자
	parseResult = wordParser(word[7]);
	if (parseResult == "999") return false;
	color_three_box(img,
		pointRecogX + stepPixel * 2, pointRecogY + stepPixel * 4, parseResult[0] - '0',
		pointRecogX + stepPixel * 3, pointRecogY + stepPixel * 4, parseResult[1] - '0',
		pointRecogX + stepPixel * 4, pointRecogY + stepPixel * 4, parseResult[2] - '0');

	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cout << "wrong input " << endl;
		return -1;
	}
	string inputString = argv[1];
	if (inputString.size() > 8) {
		cout << "input is longer than 8 letters" << endl;
		return -1;
	}

	char word[8];
	for (int i = 0; i < 8; i++)
		word[i] = argv[1][i];


	namedWindow("Example 01");

	Mat img;
	img.create(inputXsize, inputYsize, CV_8UC3);

	
	for (int x = 0; x < inputXsize; x++) {
		for (int y = 0; y < inputYsize; y++) {
			img.at<Vec3b>(x, y) = Vec3bBlack;
		}
	}

	bool completeFlag = color_marker(img, word);

	if (completeFlag) {
		imwrite(inputString+".jpg", img);

		imshow("Example 01", img);
		waitKey(0);
		destroyWindow("Example 01");

		return 0;
	}
	else {
		cout << "Error occured while generating marker" << endl;
		return -1;
	}

}