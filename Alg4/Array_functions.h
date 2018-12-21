#pragma once
class Array {
private:
	size_t size;
	int *array;
	char *char_array;
	void MoveDown(int root, int bottom);
	void quicksort(size_t left, size_t right);
public:
	
	Array(size_t elements);
	~Array();
	void print();
	void print_char();
	int BinarySearch(int key);
	void QuickSort();
	void BubbleSort();
	void HeapSort();
	void BogoSort();
	void CountingSort();
	bool is_equal(Array *arr2);
	bool is_equal_char(Array *arr2);
	size_t get_size();
};
