#include "multistack.h"
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������ ����������:" << endl;
	int m = 1;

	TMultiStack<int> mStack(4, 16);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			mStack.Set(i, m);
			cout <<"�������<" << m++ << "> ����������� " << i + 1 << " �����" << "\n";
		}

		cout << "��������� �����: \n";
		mStack.Print();
		cout << "\n";

		cout << "������������ �����: \n";
		for (int i = 0; i < 3; i++)
			cout << "Get element " << mStack.Get(i) << " from " << i + 1 << " stack" << endl;

		mStack.Print();

		cout << "\n����������� �����������: \n" << endl;
		mStack.Set(3, 10);
		mStack.Print();

		return 0;
}