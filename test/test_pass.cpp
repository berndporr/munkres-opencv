#include "munkres-opencv.h"

#include <stdio.h>

void compare(cv::Mat_<int>a, cv::Mat_<int>b) {
	for ( int row = 0 ; row < a.rows ; row++ ) {
		for ( int col = 0 ; col < a.cols ; col++ ) {
			std::cout.width(2);
			std::cout << b(row,col) << ",";
			assert(a(row,col) == b(row,col));
		}
		std::cout << std::endl;
	}
}

int main (int,char**)
{
	return 0;
}
