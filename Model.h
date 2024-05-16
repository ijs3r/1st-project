#ifndef MODEL_H
#define MODEL_H
#include <iostream>
/// <summary>
/// ������������ ������� ����� ����������� ����� � ������ ������ �� ������
/// </summary>
/// <param name="n">���������� �����</param>
/// <param name="points">������ ��� ��������� {x,y} (n �����)</param>
/// <param name="m">������� ����� ����������� ����� � ������ ������ �� ������</param>
/// <param name= "i">�������� ���������: ������ 1-� ����� </param>
/// <param name= "j">�������� ���������: ������ 2-� ����� </param>
/// <returns></returns>
 void FindPoints(double** points, int n, int& i, int& j, int& m) {
	int mini = -1, minj= -1;
	for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j < n; ++j) {
			m = 0;
			double a = (points[j][0] - points[i][0]), b = (points[j][1] - points[i][1]);
			for (int k = 0; k < n; ++k) {
				if (k == i || k == j)continue;
				double d = b * (points[k][0] - points[i][0]) - a * (points[k][1] - points[i][1]);
				if (d > 0.0) m++;
				else if (d < 0.0)m--;
			}
			if (m == 0) return;
			if (mini < 0 && abs(m) == 1) {
				mini = i;
				minj = j;
			}
		}
	}
	i = mini;
	j = minj;
	m = 1;
}
#endif