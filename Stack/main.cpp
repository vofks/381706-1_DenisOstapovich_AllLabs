#include "stack.h"

int main()
{
	int n;
	setlocale(LC_ALL, "Rus");
  cout << "Ââåäèòå ðàçìåð ñòåêà n: \n ";  
  cin >> n;
  
  TStack<int> stack(n);
  for (int i = 0; i < n; i++)
    stack.Push(i);

  cout << "Ñòåê :\n";
  stack.Print();

  TStack<int> stack2(stack);
  cout << "Ñòåê 2:\n";
  stack2.Print();

  if (stack2 == stack)
  cout << "Ñòåêè îäèíàêîâûå";

  cout << "Ýëåìåíò ñ âåðøèíû ñòåêà: " << stack.Pop();

  cout << "Îáíîâë¸ííûé ñòåê:\n";
  stack.Print();

  if (stack2 != stack)
    cout << "Ñòåêè ðàçíûå\n";
  
  return 0;
}
