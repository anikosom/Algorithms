// Lab_3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <locale.h>
#include <string>
#include "Heap.h"
#include "Vector.h"
using namespace std;


int main()
{
	
	int array[13] = { 0, 1, 8, 2, 5, 6, 6, 0, 1, 2, 4, 5, 7 };
	
	Heap heap(13, array);
	setlocale(LC_ALL, "rus");
	cout << "Исходный массив:\n";
	heap.print();
	cout << "\n\n";
	heap.HeapSort();
	cout << "Отсортированный массив:\n";
	heap.print();
	
	string command;
		cout << "\nВведите команду: ";
		cin >> command;
		if (command == "find") {
			cout << "\nВведите ключ: ";
			int key;
			cin >> key;
			if (heap.contains(key))
				cout << "Такой элемент есть в куче\n";
			else cout << "Такого элемента нет\n";
		}
		else if (command == "insert") {
			cout << "\nВведите ключ: ";
			int key;
			cin >> key;
			heap.insert(key);
		}
		else if (command == "remove") {
			cout << "\nВведите ключ: ";
			int key;
			cin >> key;
			heap.remove(key);
		}
		else if (command == "1") {
			
			cout << 0 % 2 << endl;
		}
		
		cout << endl << endl;
		heap.print_to_console();
		cout << endl << endl;
		Heap::Iterator * it1 = heap.createDFTIterator();
		Heap::Iterator * it2 = heap.createBFTIterator();
		
		cout << endl << "Обход в глубину" << endl;
		while (it1->hasNext() ) 
			cout << it1->next() << " ";
		
		
		cout << endl << "Обход в ширину" << endl;
		while (it2->hasNext())
			cout << it2->next() << " ";
		cout << "\n\n";

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
