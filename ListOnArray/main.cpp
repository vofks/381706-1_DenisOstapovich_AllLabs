#include "listonarray.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	cout << "������� ������ ������: \n";	
	cin >> n;
	TArrayList<int> list(n), reversedList(n);	
	
	for (int i = 1; i <= n; i++)
	{
		cout << "����� � ������: " << i << endl;
		list.PushFront(i);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "����� � �����: " << i << "\n";
		reversedList.PushBack(i);
	}

	cout << "� ���������� �������� ������: \n";
	list.Print();
	reversedList.Print();
	
	while(!list.IsEmpty()) cout << list.PopBack();
	
	return 0;
}
