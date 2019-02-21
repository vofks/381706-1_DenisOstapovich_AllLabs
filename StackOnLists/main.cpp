#include "stackonlists.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	cout << "������� ������ ������: \n";	
	cin >> n;
	TStackList<int> stack(n);

	for (int i = 0; i < n; i++)
	{
		cout << "�������� � ���� �������: " << i << "\n";
		stack.Push(i);
	}

	cout << "���������� ����: \n";
	stack.Print();
	
	while (!stack.IsEmpty())
		cout << "\n ��������� ������� � ������� �����: " << stack.Pop();
	cout << "\n ���� ����";

	return 0;
}