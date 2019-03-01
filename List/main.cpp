#include "list.h"

int main()
{ 
	setlocale(LC_ALL, "Russian");

	int beginCount, endCount;
	TList<int> list;

	cout << "¬ведите число элементов, которое вы хотите поместить в начало списка: \n";	
	cin >> beginCount;

	for (int i = 1; i <= beginCount; i++) list.PushFront(i);

	cout << "¬ведите число элементов, которое вы хотите поместить в конец списка: \n";
	cin >> endCount;

	for (int i = 1; i <= endCount; i++) list.PushBack(i);

	cout << "¬ результате получен список: \n";
	list.Print();

	cout << "Ёлемент в начале списка: \n" << list.PopFront() << "\n";
	cout << "Ёлемент в конце списка: \n" << list.PopBack() << "\n";

	cout << "“еперь список выгл€дит так: \n";
	list.Print();

	return 0;
}

