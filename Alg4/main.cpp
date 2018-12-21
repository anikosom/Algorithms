
#include "pch.h"
#include <iostream>
#include "Array_functions.h"
using namespace std;
int main()
{
	cout << "Array:" << endl;
	int mass[4] = { 5, 3, 6, 1 };
	//char mass[10] = { 2, 44, 23, 33, 34, 24, 6, 27, 4, 3 };
	Array arr(4); 
	arr.array = mass;
	arr.print();
	cout << endl;
	//cout << arr.BinarySearch(3) << endl;
	//arr.QuickSort();
	arr.BubbleSort();
	//arr.HeapSort();
	//arr.BogoSort();
	//arr.CountingSort();
	cout << "Sorted array:\n";
	arr.print();
	cout << endl;

	

}

