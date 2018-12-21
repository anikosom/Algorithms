#pragma once
#include "Vector.h"
using namespace std;
class Heap {
private:
	Vector array;
	void MoveDown(int root, int bottom);

public:
	Heap();
	Heap(size_t elements, int * arr);
	~Heap();
	void print();
	size_t size();
	bool is_empty();
	bool contains(int key);
	void insert(int key);
	void remove(int key);
	void HeapSort();
	void print_to_console();

	class Iterator
	{
	public:
		virtual int next() = 0;
		virtual bool hasNext() = 0;
	};

	class HeapDFTIterator : public Iterator
	{
		Vector heapVector;
		size_t curIndex;
		Vector stack;

	public:
		HeapDFTIterator(Vector);

		int next() override;
		bool hasNext() override;
	};

	class HeapBFTIterator : public Iterator
	{
		Vector heapVector;
		size_t curIndex;

	public:
		HeapBFTIterator(Vector);

		int next() override;
		bool hasNext() override;
	};

	Iterator * createDFTIterator(); 
	Iterator * createBFTIterator(); 
	//индексирование 
	int operator [](const size_t); 
};