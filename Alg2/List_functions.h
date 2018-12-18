#pragma once
struct Node {
	int data;
	Node *next, *prev;
};



class List {
private:
	size_t elements;
	Node *head, *tail;

public:

	List() : head(NULL), tail(NULL), elements(0) {};
	~List();
	List(int * mass, size_t size);
	void push_back(int x);
	void push_front(int x);
	void pop_back();
	void pop_front();
	void print_to_console();
	void clear();
	void insert(int value, size_t index);
	void set(int value, size_t index);
	int at(size_t index);
	void remove(size_t index);
	bool isEmpty();
	size_t get_size();
	int find_last(List * list);
	bool check_index(size_t index);
	bool is_equal(List * list_2);
};
