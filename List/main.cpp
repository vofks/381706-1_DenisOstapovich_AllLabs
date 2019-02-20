#include "list.h"

int main()
{ 
	setlocale(LC_ALL, "Russian");

	int beginCount, endCount;
	TList<int> list;

	cout << "������� ����� ���������, ������� �� ������ ��������� � ������ ������: \n";	
	cin >> beginCount;

	for (int i = 1; i <= beginCount; i++) list.PushFront(i);

	cout << "������� ����� ���������, ������� �� ������ ��������� � ����� ������: \n";
	cin >> endCount;

	for (int i = 1; i <= endCount; i++) list.PushBack(i);

	cout << "� ���������� ������� ������: \n";
	list.Print();

	cout << "������� � ������ ������: \n" << list.PopFront() << "\n";
	cout << "������� � ����� ������: \n" << list.PopBack() << "\n";

	cout << "������ ������ �������� ���: \n";
	list.Print();

	return 0;
}

