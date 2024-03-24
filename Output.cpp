#include "Output.h"
void Print(double** points, int i, int j,int m) {
	
	std::cout <<i<<' '<<j << " (" << points[i][0] << ", " << points[i][1] << "), (" << points[j][0] << ", " << points[j][1] << ") difference = " << m << "\n";
}