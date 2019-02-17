#include "Stack.h"


int main()
{
	int n;
	setlocale(LC_ALL, "Rus");
  cout << "Введите размер стека n: \n ";  
  cin >> n;
  
  TStack<int> stack(n);
  for (int i = 0; i < n; i++)
    stack.Push(i);

  cout << "Стек :\n";
  stack.Print();

  TStack<int> stack2(stack);
  cout << "Стек 2:\n";
  stack2.Print();

  if (stack2 == stack)
  cout << "Стеки одинаковые";

  cout << "Элемент с вершины стека: " << stack.Pop();

  cout << "Обновлённый стек:\n";
  stack.Print();

  if (stack2 != stack)
    cout << "Стеки разные\n";
  
  return 0;
}