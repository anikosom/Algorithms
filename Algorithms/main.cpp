#include "pch.h"
#include <iomanip>
#include <iostream>
#include <locale.h>
#include "Array_functions.h"
#define SIZE 1
#define VALUE 2
using namespace std;



int get_value( int var)
{
	while (true) {
		int value;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Неверный ввод. Попробуйте снова.\n";
		}
		else if (var == SIZE) {
			if (value > 14 || value < 0)
				cout << "Пожалуйста, введите число от 0 до 15.\n";
			else
			{
				cin.ignore(32767, '\n');
				return value;
			}
		}
		else
		{
			cin.ignore(32767, '\n');
			return value;
		}
		
	}
}
int main()
{
	int init_value;
	setlocale(LC_ALL, "rus");
    cout << "Введите размер массива\n"; 
	cout << "Количество строк:";
	size_t rows = get_value(SIZE);
	cout << "Количество столбцов:";
	size_t columns = get_value(SIZE);
	cout << "Начальное значение:";
	init_value = get_value(VALUE);
	int **array = new int*[rows];
	for (int i = 0; i < rows; i++)
		array[i] = new int[columns];
	fill_array(array, rows, columns, init_value);
	print_array(array, rows, columns);
	for (int i = 0; i < rows; i++)
		delete array[i];
	delete[] array;
	
}
