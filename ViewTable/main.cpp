#include "viewtable.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  setlocale (LC_ALL, "Russian");

  TElem<int> a1("D", 35), a2("E", 17), a3("N", 76), e4(a1), a5;
  TViewTable<int> table(10);
  
  table.Put(a1);
  table.Put(a2);
  table.Put(a3);

  cout << table << endl;
  cout << "�������� �������� ������ � ������� ������: " << endl;
  table.Put(e4);
  cout << "\n������� �������� ������ ��������:" << endl;
  cin >> a5;
  table.Put(a5);
  cout << "�������\n" << table << endl;
  cout << "�������� ����� �� ����� D:\n" << table.Search("D") << endl;
  cout << "������ �� ������ � ������ E\n" << table["E"] << endl;

  return 0;
}
