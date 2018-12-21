#include "pch.h"
#include <iostream>
#include <locale.h>
#include "Array_functions.h"

using namespace std;
Array::~Array(){
	size = 0;
}
Array::Array(size_t elements, int * arr) {
	size = elements;
	array = arr;
}
Array::Array(size_t elements, char * arr) {
	size = elements;
	char_array = arr;
}
size_t Array::get_size() {
	return size;
}
void Array::print() {
	for (size_t i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}
void Array::print_char() {
	for (size_t i = 0; i < size; i++) {
		cout << char_array[i] << " ";
	}
}
int Array::BinarySearch(int key) {

	if (get_size() != 0) {
		bool success = false;
		size_t left = 0;
		size_t right = get_size();
		size_t middle;

		while ((left <= right) && (success != true)) {
			middle = (left + right) / 2;

			if (array[middle] == key) success = true;
			if (array[middle] > key) right = middle - 1;
			else left = middle + 1;
		}
		if (success)
			return middle;
		else return -1;
	}
	else throw out_of_range("Array is empty");
}
void Array::QuickSort() {
	size_t left = 0;
	size_t right = size - 1;
	quick_sort(left, right);
}
void Array::quicksort(size_t left, size_t right) {
	if (left > size - 1 || right > size - 1)
		throw out_of_range("Incorrect input");
		if (get_size() != 0) {
			int point;
			int left_prim = left;
			int right_prim = right;
			point = array[left];
			while (left < right)
			{
				while ((array[right] >= point) && (left < right))
					right--;
				if (left != right)
				{
					array[left] = array[right];
					left++;
				}
				while ((array[left] <= point) && (left < right))
					left++;
				if (left != right)
				{
					array[right] = array[left];
					right--;
				}
			}
			array[left] = point;
			point = left;
			left = left_prim;
			right = right_prim;
			if (left < point)
				quicksort(left, point - 1);
			if (right > point)
				quicksort(point + 1, right);
		}
		else throw out_of_range("Array is empty");
}
 
void Array::BubbleSort() {
	if (get_size() != 0) {
		int temp; 
	
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (array[j] > array[j + 1]) {
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}
	else throw out_of_range("Array is empty");
}
void Array::MoveDown(int root, int bottom)
{
	int max_child;
	int done = 0; 
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    
			max_child = root * 2;   
		else if (array[root * 2] > array[root * 2 + 1])
			max_child = root * 2;
		else
			max_child = root * 2 + 1;
		
		if (array[root] < array[max_child])
		{
			int temp = array[root]; 
			array[root] = array[max_child];
			array[max_child] = temp;
			root = max_child;
		}
		else 
			done = 1; 
	}
}

void Array::HeapSort()
{
	if (get_size() != 0) {
		for (int i = (size / 2) - 1; i >= 0; i--) {
			MoveDown(i, size - 1);
		}
		for (int i = size - 1; i >= 1; i--)
		{
			int temp = array[0];
			array[0] = array[i];
			array[i] = temp;
			MoveDown(0, i - 1);
		}
	}
	else throw out_of_range("Array is empty");
}
void Array::BogoSort() {
	if (get_size() != 0) {
		int i = 0, temp;
		while (i < size - 1)
		{
			if (array[i + 1] < array[i])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				i = 0;
			}
			else i++;
		}
	}
	else throw out_of_range("Array is empty");
}
void Array::CountingSort() 
	{
	if (get_size() != 0) {
		int max = 128;
		int min = -127;
		int * c_array = new int[max - min + 1];

		for (int i = min; i <= max; ++i)
			c_array[i - min] = 0;

		for (size_t i = 0; i < size; ++i)
			++c_array[char_array[i] - min];

		size_t index = 0;
		for (int i = min; i <= max; ++i) {
			while (c_array[i - min] != 0 && index < size) {
				if (c_array[i - min] != 0) {
					char_array[index] = i;
					index++;
				}
				c_array[i-min]--;
			}
		}
		delete[] c_array;
	}
	else throw out_of_range("Array is empty");
}
bool Array::is_equal( Array *arr2 ) {
	if ( get_size() != arr2->get_size()) return false;
	for (size_t i = 0; i < get_size(); i++) {
			if (array[i] != arr2->array[i]) return false;
	}
	return true;
}
bool Array::is_equal_char(Array *arr2) {
	if (get_size() != arr2->get_size()) return false;
	for (size_t i = 0; i < get_size(); i++) {
		if (char_array[i] != arr2->char_array[i]) return false;
	}
	return true;
}
