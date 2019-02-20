#include "queue.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, i = 0;	

	cout << "Введите размер очереди\n";
	cin >> n;
	TQueue<int> queue(n);

	while (!queue.IsFull())
	{
		queue.Push(i);
		cout << "Pushed: " << i << endl;
		i++;
	}

	cout << "Очередь полна\n";

	while (!queue.IsEmpty())
	{
		n = queue.Pop();
		cout << "Popped: " << n << endl;
	}

	cout << "Очередь пуста\n";

	return 0;
}
