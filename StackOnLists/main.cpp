#include "stackonlists.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	cout << "Введите размер списка: \n";	
	cin >> n;
	TStackList<int> stack(n);

	for (int i = 0; i < n; i++)
	{
		cout << "Помещаем в стек элемент: " << i << "\n";
		stack.Push(i);
	}

	cout << "Полученный стек: \n";
	stack.Print();
	
	while (!stack.IsEmpty())
		cout << "\n Извлекаем элемент с вершины стека: " << stack.Pop();
	cout << "\n Стек пуст";

	return 0;
}