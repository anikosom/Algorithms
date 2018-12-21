#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Heap.h"
#include "Vector.h"
using namespace std;

Heap::~Heap() {
	array.~Vector();
}
Heap::Heap() {
	
}
Heap::Heap(size_t elements, int * arr) {
	Vector temp(arr, elements);
	array = temp;
	HeapSort();
}
size_t Heap::size() {
	return array.size();
}
void Heap::print() {
	for (size_t i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
}
bool Heap::is_empty() {
	if (array.size() == 0)
		return true;
	else return false;
}
void Heap::insert(int key) {
	array.push_back(key);   // � ����� ����������� �������
	size_t i;
	i = size() - 1;
	array[i] = key;
	while (((i - 1) / 2) >= 0 && i > 0) { //�� ����������� ������, ���� ��� �������� ������ �������� ��������
		if (array[i] > array[(i - 1) / 2]) {
			int temp = array[i];
			array[i] = array[(i - 1) / 2];
			array[(i - 1) / 2] = temp;
		}
		i = (i - 1) / 2;
	}
}
void Heap::remove(int key){
	if (is_empty())
		throw out_of_range("Array is empty");
	int index = array.contains(key); // ���������, ���� �� ����� ������� � ����
	if (index >= 0) {
		array[index] = array[size() - 1];  // �� ��� ����� ��������� ��������� ������� ����������� ��� �����
		array.pop_back();
		HeapSort();    // ������������� ������ �������� ��������� ����
	}
}
bool Heap::contains(int key) {
	if (is_empty())
		throw out_of_range("Array is empty");
	if (array.contains(key) >= 0)
		return true;
	else return false;
}
void Heap::MoveDown(int root, int bottom)  //���� �������� ������� ������ �������� ��������, ��� �������� �������
{
	int max_child;
	int done = 0;
	while ((root * 2 + 1 <= bottom) && (!done))
	{
		if (root * 2 + 1 == bottom)
			max_child = root * 2 + 1;
		else if (array[root * 2 + 1] > array[root * 2 + 2])
			max_child = root * 2 + 1;
		else
			max_child = root * 2 + 2;

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
void Heap::HeapSort() // �������������� ������� �� ��������� ����
{
	if (array.size() == 0) 
		throw out_of_range("Array is empty");
	for (int i = (array.size() / 2); i >= 0; i--) 
		MoveDown(i, array.size() - 1);
}
void Heap::print_to_console() {
	if (array.size() == 0)
		throw out_of_range("Array is empty");
	cout << endl;
	size_t index = 0;
	size_t num_levels = floor(log2(array.size()));  //������ ���������� ��������
	size_t cur_level = num_levels;  //������� �������, ��� �������� �������� ��������� ���� � �������� �������
	for (size_t i = 0; i <= num_levels; i++) {
		size_t spaces = pow(2, cur_level) - 1;  //������ ���������� ��������
		for (size_t j = 0; j < pow(2, i); j++) {
			cout << " ";
			for (size_t k = 0; k < spaces; k++) {
				if (k >= spaces / 2 && (index * 2 + 1) < size())   // ���� ���� �������, ��������� ����� ����� �� ��������
					cout << "_";
				else cout << " ";
			}
			if (index < array.size()) {
				cout << array[index];  // ����� �������� ����
				index++;
			}
			else return;
			for (size_t k = 0; k < spaces; k++) {
				if (k <= spaces / 2 && (index * 2) < size()) //// ���� ���� �������, ��������� ����� ������ �� ��������
					cout << "_";
				else cout << " ";
			}

		}
		cout << endl;
		cur_level--;  //������� �� ��������� �������
	}
}
//����� � �������
Heap::HeapDFTIterator::HeapDFTIterator(Vector itHeapVector)
{
	heapVector = itHeapVector;
	curIndex = 0;
}
int Heap::HeapDFTIterator::next()
{
	if (curIndex >= heapVector.size())
		throw "OutOfRangeException";
	if (curIndex == 0) {
		curIndex++;
		return heapVector[0];
	}
	size_t temp = curIndex;
	if (curIndex % 2 != 0 ) {   //���� ������ �������� ��������
		if (curIndex + 1 < heapVector.size()) {
			stack.push_back(curIndex + 1);  //���������� � ���� ��� �������� ������ �������, ���� �� ����
		}
		curIndex = curIndex * 2 + 1;  //�������� ������� � �������
		if (curIndex > heapVector.size() - 1) {
			curIndex = temp + 1;  //���� ������� ���, �������� ������� � ��������� ��������
			if (curIndex > heapVector.size() - 1) {
					if (stack.size() != 0) {
						curIndex = stack[stack.size() - 1];  // ���� ������� ��� ���������, ��������� � ���������� �������� �� �����
						stack.pop_back(); 
					}
					else curIndex = curIndex * 2 + 1;
			}
		}
	}
	else {                                   //���� ������ ������
		curIndex = curIndex * 2 + 1;         //�������� ������� � �������

		if (curIndex > heapVector.size() - 1) {  //���� ������� ���, ��������� � �������� �� �����
			stack.pop_back();
			if (stack.size() != 0) {
				curIndex = stack[stack.size() - 1];
				stack.pop_back();
			}
			else 
				curIndex = curIndex * 2 + 1;
		}
	}
	return heapVector[temp];
	
}
bool Heap::HeapDFTIterator::hasNext()
{
	if (curIndex < heapVector.size())
		return true;
	else
		return false;
}


Heap::HeapBFTIterator::HeapBFTIterator(Vector itHeapVector)
{
	heapVector = itHeapVector;
	curIndex = 0;
}
int Heap::HeapBFTIterator::next()
{
	if (curIndex >= heapVector.size())
		throw "OutOfRangeException";

	return heapVector[curIndex++];
}
bool Heap::HeapBFTIterator::hasNext()
{
	if (curIndex < heapVector.size())
		return true;
	else
		return false;
}

Heap::Iterator * Heap::createDFTIterator()
{
	return new HeapDFTIterator(array);
}
Heap::Iterator * Heap::createBFTIterator()
{
	return new HeapBFTIterator(array);
}


int Heap::operator[](const size_t index)
{
	return array[index];
}