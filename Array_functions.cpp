#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool is_equal(int **array1, const size_t rows1, const size_t columns1, int **array2, const size_t rows2, const size_t columns2) {
	if (rows1 != rows2 || columns1 != columns2) return false;
	for (size_t i = 0; i < rows1; i++) {
		for (size_t j = 0; j < columns1; j++)
			if (array1[i][j] != array2[i][j]) return false;
	}
	return true;
}

int fill_array(int **array, const size_t rows, const size_t columns, const int init_value) {
	int value, elem_1 = init_value;   
	// значение каждого элемента массива вычисляется в зависимости от его индексов в массиве
	for (size_t n = 0; n < rows; n++) {
		(n > columns - 1) ? elem_1 += columns : elem_1 += n;   // вычисление начального значения для первого элемента строки
		value = elem_1;
		for (size_t m = 0; m < columns; m++) {
			(n + m > rows) ? value += rows : value += m + n;
			if (n + m > columns - 1)  
				value -= (n + m - columns + 1);
			array[n][m] = value;
		}
	}
	return 0;
}

int print_array(int **array, const size_t rows, const size_t columns) {
	setlocale(LC_ALL, "rus");
	cout << "Массив:\n";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
			cout << setw(5) << left << array[i][j] << " ";
		cout << "\n";
	}
	return 0;
}