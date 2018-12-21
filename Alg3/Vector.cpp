#include "pch.h"
#include "Vector.h"

Vector::Vector()
{
	vector = nullptr;
	v_size = 0;
}
Vector::Vector(const int * numb, const size_t size)
{
	v_size = 0;
	vector = nullptr;
	for (size_t i = 0; i < size; ++i)
		push_back(numb[i]);
}

Vector::~Vector()
{
	if (vector)
		delete vector;
	vector = nullptr;
}
Vector::Vector(const Vector & secVector)
{
	v_size = secVector.v_size;

	vector = new int[v_size];

	for (size_t i = 0; i < v_size; ++i)
		vector[i] = secVector.vector[i];
}

size_t Vector::size()
{
	return v_size;
}

void Vector::push_back(const int elem)
{
	int * temp_vec = new int[v_size + 1];

	for (size_t i = 0; i < v_size; ++i)
	{
		temp_vec[i] = vector[i];
	}

	delete[] vector;

	vector = temp_vec;
	vector[v_size] = elem;
	++v_size;
}
void Vector::pop_back()
{
	if (v_size != 0) {
		int * temp_vec = new int[v_size - 1];

		for (size_t i = 0; i < v_size - 1; ++i)
		{
			temp_vec[i] = vector[i];
		}

		delete[] vector;
		vector = temp_vec;
		v_size--;
	}
}

int Vector::contains(const int elem)
{
	int index = -1;

	for (size_t i = 0; i < v_size; ++i)
		if (vector[i] == elem) {
			index = i;
			i = v_size;
		}

	return index;
}

void Vector::operator=(const Vector & secVector)
{
	v_size = secVector.v_size;

	vector = new int[v_size];

	for (size_t i = 0; i < v_size; ++i)
		vector[i] = secVector.vector[i];
}

int & Vector::operator[](const size_t index)
{
	if (index >= v_size)
		throw "IndexOutOfRangeExeption";

	return vector[index];
}