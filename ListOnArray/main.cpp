#include "listonarray.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	cout << "Введите размер списка: \n";	
	cin >> n;
	TArrayList<int> list(n), reversedList(n);	
	
	for (int i = 1; i <= n; i++)
	{
		cout << "Кладём в начало: " << i << endl;
		list.PushFront(i);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "Кладём в конец: " << i << "\n";
		reversedList.PushBack(i);
	}

	cout << "В результате получены списки: \n";
	list.Print();
	reversedList.Print();
	
	while(!list.IsEmpty()) cout << list.PopBack();
	
	return 0;
}
