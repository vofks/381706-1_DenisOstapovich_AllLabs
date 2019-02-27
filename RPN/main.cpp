#include <iostream>
#include "rpn.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	char buf[] = "(22+2)/2-7*3";
	TMyString str(buf);
	TQueue<char> queue;

	std::cout << "Математическое выражение: (22+2)/2-7*3 = ";
	queue = ConvertRPN(str);
	std::cout << Result(queue) << "\n";

	return 0;
}