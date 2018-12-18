#include "pch.h"
#include <iostream>
#include "List_functions.h"
using namespace std;


List::~List() {
	while (head) {
		tail = head->next;
		delete head;
		head = tail;
	}
	elements = 0;
}

bool List::isEmpty() {
	if (get_size() == 0)
		return true;
	else
		return false;
}

size_t List::get_size() {
	return elements;
}

void List::push_back(int x) {
	Node *temp = new Node;
	temp->next = NULL;
	temp->data = x;
	temp->prev = tail;
	if (head != NULL) {
		tail->next = temp;
		tail = temp;
		elements++;
	}
	else {
		head = tail = temp;
		elements = 1;
	}
}

void List::push_front(int x) {
	Node *temp = new Node;
	temp->next = head;
	temp->prev = NULL;
	temp->data = x;
	head = temp;
	if (!head)
		tail = temp;
	elements++;
}

void List::pop_back() {
	Node *temp = tail;
	if (temp != NULL) {
		if (temp->prev != NULL)
			temp->prev->next = NULL;
		tail = temp->prev;
		free(temp);
		--elements;
	}
}

void List::pop_front() {
	Node * temp = head;
	if (temp != NULL) {
		if (temp->next != NULL)
			temp->next->prev = NULL;
		head = temp->next;
		free(temp);
		--elements;
	}
}

void List::insert(int value, size_t index) {
	if (isEmpty())
		throw out_of_range("List is empty");
	if (!check_index(index))
		throw out_of_range("Index is greater or smaller than list size");
	if (index != 0) {
		Node *current = head;
		for (size_t i = 0; i < index - 1; i++)
			current = current->next;
		Node *temp = new Node;
		Node *p;
		temp->data = value;
		p = current->next;
		temp->next = p;
		current->next = temp;
		temp->prev = current;
		p->prev = temp;
		++elements;
	}
	else
		push_front(value);
}

int List::at(size_t index)
{
	if (isEmpty())
		throw out_of_range("List is empty");
	if (!check_index(index))
		throw out_of_range("Index is greater or smaller than list size");
	Node *temp = head;
	if (index > 0)
		for (size_t i = 0; i < index; i++)
			temp = temp->next;
	return temp->data;
}

void List::remove(size_t index) {
	if (isEmpty())
		throw out_of_range("List is empty");
	if (!check_index(index)) 
		throw out_of_range("Index is greater or smaller than list size");
	Node *temp = head;
	if (index == 0)
		pop_front();
	else if (index == get_size() - 1)
		pop_back();
	else {
		for (size_t i = 0; i < index; i++)
			temp = temp->next;
		temp->prev->next = temp->next;

		free(temp);
		--elements;
	}
	
}

void List::print_to_console() {
	Node *temp = head;
	for (size_t i = 0; i < get_size(); i++) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void List::set(int value, size_t index) {
	if (!check_index(index)) 
		throw out_of_range("Index is greater or smaller than list size");
	if (index < get_size()) 
		insert(value, index);
	else push_back(value);
	remove(index + 1);
}
int List::find_last(List * list) {
	if (isEmpty() || list->isEmpty())
		throw out_of_range("There's an empty list");
	size_t index = get_size() - 1;
	Node * current = tail;
	Node * current2 = list->tail;
	bool full_list = false;
	for (size_t i = 0; i < get_size() - 1; i++) {
		if (current->data == current2->data) {
			if (full_list == true || current2 == list->tail) {
				if (current2->prev != NULL)
					current2 = current2->prev;
				else return index;
				full_list = true;
			}
		}
		else if (full_list == true) {
			full_list = false;
			current2 = list->tail;
		}
		current = current->prev;
		--index;
	}
	return -1;
	
}
 List::List(int * mass, size_t size) {
	 head = tail = NULL;
	 elements = 0;
	for (size_t i = 0; i < size; i++) {
		push_back(mass[i]);
	}
}

bool List::is_equal( List * list_2) {
	if (isEmpty() || list_2->isEmpty())
		throw out_of_range("There's an empty list");
	if (get_size() == list_2->get_size()) {
		bool is_equal = true;
		Node * current1 = head;
		Node * current2 = list_2->head;
		for (size_t i = 0; i < get_size() - 1; i++) {
			if (current1->data != current2->data)
				is_equal = false;
			current1 = current1->next;
			current2 = current2->next;
		}
		if (current1->data != current2->data)
			is_equal = false;
		return is_equal;

	}
	else return false;
}

bool List::check_index(size_t index) {
	if (index >= elements) 
		return false;
	else return true;
}
