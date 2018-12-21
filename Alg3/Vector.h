#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Vector
{
	int * vector;
	size_t v_size;
public:

	Vector();
	Vector(const int *, const size_t);
	Vector(const Vector & secVector);
	~Vector();

	size_t size(); 
	void push_back(const int);
	void pop_back();
	int contains(const int); 
	//присваивание и индексирование 
	void operator =(const Vector & secVector); 
	int & operator [](const size_t index); 
};