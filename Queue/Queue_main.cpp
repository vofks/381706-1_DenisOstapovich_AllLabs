#include "queue.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, i = 0;	

	cout << "������� ������ �������\n";
	cin >> n;
	TQueue<int> queue(n);

	while (!queue.IsFull())
	{
		queue.Push(i);
		cout << "Pushed: " << i << endl;
		i++;
	}

	cout << "������� �����\n";

	while (!queue.IsEmpty())
	{
		n = queue.Pop();
		cout << "Popped: " << n << endl;
	}

	cout << "������� �����\n";

	return 0;
}
