

#include "pch.h"
#include <iostream>
#include "List_functions.h"
using namespace std;


size_t get_index() {
	size_t index;
	cout << "Index:";
	cin >> index;
	return index;
}
int main()
{
	
	int mass_1[10] = { 12, 34, 23, 23, 47, 12, 34, 23, 4, 65 };
	List DLL(mass_1, 10);
	cout << "List: ";
	DLL.print_to_console();
	
	int mass_2[3] = { 12, 34, 23 };
	List DLL2(mass_2, 3);
	//cout << "\nSecond list: ";
	//DLL.print_to_console();

	size_t operation = 5;
	//cout << "\n0 - exit\n1 - push_back\n2 - push_front\n3 - pop_back\n4 - pop_front\n5 - insert\n6 - at\n7 - remove\n8 - get_size\n9 - print_to_console\n10 - clear\n11 - set\n12 - isEmpty\n13 - find_last";
	while (operation != 0) {
		cout << "\nCommand:";
		cin >> operation;
		if (operation == 1) {
			cout << "Value:";
			int value;
			cin >> value;
			DLL.push_back(value);
		}
		else if (operation == 2) {
			cout << "Value:";
			int value;
			cin >> value;
			DLL.push_front(value);
		}
		else if (operation == 3)
			DLL.pop_back();
		else if (operation == 4)
			DLL.pop_front();
		else if (operation == 5)
		{
			cout << "Value:";
			int value;
			cin >> value;
			size_t index;
			index = get_index();
			DLL.insert(value, index);
		}
		else if (operation == 6) {
				size_t index = get_index();
				cout << DLL.at(index) << endl;
		}
		else if (operation == 7) {
			if (!DLL.isEmpty()) {
				size_t index = get_index();
				DLL.remove(index);
			}
			else cout << "List is empty" << endl;
		}
		else if (operation == 8)
			cout << "size:" << DLL.get_size() << endl;
		else if (operation == 9)
			DLL.print_to_console();
		else if (operation == 10)
			DLL.~List();
		else if (operation == 11) {
			if (!DLL.isEmpty()) {
				cout << "Value:";
				int value;
				cin >> value;
				size_t index = get_index();
				DLL.set(value, index);
			}
			else cout << "List is empty" << endl;
		}
		else if (operation == 12) {
			if (DLL.isEmpty())
				cout << "Empty\n";
			else cout << "Not empty\n";
		}
		else if (operation == 13) {
			size_t index = DLL.find_last(&DLL2);
			if (index < DLL.get_size() && index >= 0) {
				cout << "Index of the last list: ";
				cout << index << endl;
			}
		}
	}
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
