#include "rpn.h"
#include <cstdlib>

bool IsOperation(char _op)
{
	return (_op == '+' || _op == '-' || _op == '*' || _op == '/' || _op == '(' || _op == ')');
}

int GetPriority(const char _op)
{
	switch (_op)
	{
	case '(':
		return 1;
	case ')':
		return 1;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	default:
		throw -1;
	}
}

TQueue<char> ConvertRPN(TMyString _str)
{
	int op = 0;
	int cl = 0;
	TQueue<char> Queue(_str.GetLength() * 3);
	TStack<char> Stack(_str.GetLength() * 3);
	for (int i = 0; i < _str.GetLength(); i++)
	{
		if (i == 0)
		{
			if (_str[0] == '-')
			{
				Queue.Push('[');
				Queue.Push('0');
				Queue.Push(']');
			}
			else if (IsOperation(_str[0]))
				if (GetPriority(_str[0]) != 1)
					throw -1;
		}
		if (isdigit(_str[i]))
		{
			Queue.Push('[');
			while ((i < _str.GetLength()) && isdigit(_str[i + 1]))
			{
				Queue.Push(_str[i]);
				i++;
			}
			Queue.Push(_str[i]);
			Queue.Push(']');
		}
		else if (Stack.IsEmpty() && IsOperation(_str[i]))
		{
			Stack.Push(_str[i]);
			if (_str[i] == '(')
				op++;
			if (_str[i] == ')')
				throw -1;
		}
		else if (IsOperation(_str[i]))
		{
			if (_str[i] == '(')
			{
				Stack.Push(_str[i]);
				op++;
			}
			else if (_str[i] == ')')
			{
				cl++;
				while (Stack.GetTop() != '(')
					Queue.Push(Stack.Pop());
				Stack.Pop();
			}
			else
			{
				int p = GetPriority(_str[i]);
				if (p > GetPriority(Stack.GetTop()))
					Stack.Push(_str[i]);
				else if (p <= GetPriority(Stack.GetTop()))
				{
					while (!Stack.IsEmpty() && p <= GetPriority(Stack.GetTop()))
						Queue.Push(Stack.Pop());
					Stack.Push(_str[i]);
				}
			}
		}
		else if (_str[i] != '\0')
			throw -1;
	}
	while (!Stack.IsEmpty())
		Queue.Push(Stack.Pop());
	if (op != cl)
		throw -1;
	return Queue;
}

double Result(TQueue<char> _queue)
{
	double result = 0;
	TStack<double> Stack(_queue.GetSize());
	if (IsOperation(_queue.Top()))
		throw -1;
	int i = 0;
	int dit = 0;
	int t = 0;
	while (!_queue.IsEmpty())
	{
		i++;
		char A = _queue.Pop();
		if (A == '[')
		{
			dit++;
			A = _queue.Pop();
			double tmp = std::atof(&A);
			while (_queue.Top() != ']' && !_queue.IsEmpty())
			{
				A = _queue.Pop();
				tmp = tmp * 10 + std::atof(&A);
			}
			_queue.Pop();
			Stack.Push(tmp);
		}
		else if (IsOperation(A))
		{
			double B = Stack.Pop();
			double C = Stack.Pop();
			double D = 0;
			if (A == '+')
				D = C + B;
			if (A == '-')
				D = C - B;
			if (A == '*')
				D = C * B;
			if (A == '/')
				D = C / B;
			Stack.Push(D);
		}
		else
			throw -1;
		if (i == 2 && dit != 2)
			throw -1;
	}
	result = Stack.Pop();
	if (!Stack.IsEmpty())
		throw -1;
	return result;
}