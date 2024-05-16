
#include <iostream>
#include <fstream>
/// <summary>
/// Считывает данные, вкючает опрос пользователя
/// </summary>
/// <param name="mode">Режим работы: 0-ввод с файла, 1-ввод с командной строки</param>
/// <param name= "n">Кол-во координат</param>
/// <param name= "buffer">массив пар координат {x,y} (n точек)</param>
/// <returns>1-успешное завершение, 0-ошибка ввода</returns>
bool GetInput(double**& buffer, int& n,char mode);