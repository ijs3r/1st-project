#include "Menu.h"
#include "Output.h"
#include "Input.h"
#include "Model.h"
//-----------------
int main() {
	int res = menu();
	int n, i, j,m;
	double** points = 0;
	while (res != 0) {
		switch (res) {
		case 1:
			if(GetInput(points, n, 1))std::cout<<"Data was received successfully\n"
			;break;
		case 2:
			if(GetInput(points, n, 0))std::cout <<"Data was received successfully\n"; 
			break;
		case 3:
			if (points == 0) {
				std::cout << "No data\n";
				break;
			}
			FindPoints(points, n, i, j,m);
			Print(points, i, j,m);
			break;
		}
		res = menu();
	}
	if (points) {
		for (int i = 0; i < n; ++i)delete[]points[i];
		delete[]points;
	}
	std::cout << "Thanks for using our program";
	return 0;
}
