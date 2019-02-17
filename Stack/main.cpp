#include "Stack.h"


int main()
{
	int n;
	setlocale(LC_ALL, "Rus");
  cout << "������� ������ ����� n: \n ";  
  cin >> n;
  
  TStack<int> stack(n);
  for (int i = 0; i < n; i++)
    stack.Push(i);

  cout << "���� :\n";
  stack.Print();

  TStack<int> stack2(stack);
  cout << "���� 2:\n";
  stack2.Print();

  if (stack2 == stack)
  cout << "����� ����������";

  cout << "������� � ������� �����: " << stack.Pop();

  cout << "���������� ����:\n";
  stack.Print();

  if (stack2 != stack)
    cout << "����� ������\n";
  
  return 0;
}