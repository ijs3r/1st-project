#include "Input.h"
//-----------------
inline void clear(double**& buffer, int n) {
	for (int i = 0; i < n; ++i)delete[]buffer[i];
	delete[]buffer;
	buffer = 0;
}
char GetInputCin(double**& buffer, int& n) {
	std::cin >> n;
	if (n < 2) {
		std::cout << "Too little data\n";
		return -1;
	}
	buffer = new double* [n];
	for (int i = 0; i < n; ++i) {
		buffer[i] = new double[2];
		std::cin >> buffer[i][0] >> buffer[i][1];
	}
	return 1;
}
char GetInputFile(const char* file_name, double**& buffer, int& n) {
	std::ifstream file(file_name);
	if (!file) return 0;
	file >> n;
	if (n < 2) {
		std::cout << "Too little data\n";
		return -1;
	}
	buffer = new double* [n];
	for (int i = 0; i < n; ++i) buffer[i] = new double[2];
	for (int i = 0; i < n; ++i) {
		if (!(file >> buffer[i][0])) {
			std::cout << "Missing data\n";
			clear(buffer, n);
			return -1;
		}
		file >> buffer[i][1];
	}
	file.close();
	return 1;
}
bool GetInput(double**& buffer, int& n,char mode) {
	
	switch (mode)
	{
		case 0:
			while (1) {
				char ans = GetInputCin(buffer, n);
				if (ans == 1)return 1;
				else if (ans == -1)return 0;	
			}
		break;
		case 1:
			while (1) {
				std::cout << "File name:";
				char file_name[255];
				std::cin.getline(file_name, 255, '\n');
				std::cin.getline(file_name, 255, '\n');
				char ans = GetInputFile(file_name,buffer, n);
				if (ans == 1)return 1;
				else if (ans == -1)return 0;
			}
		break;
	default:break;
	}
	return 0;
}