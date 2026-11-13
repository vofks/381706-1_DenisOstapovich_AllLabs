#pragma once
#include "queue.h"
#include "mystring.h"

bool IsOperation(char _op);
int GetPriority(const char _op);
TQueue<char> ConvertRPN(TMyString _str);
double Result(TQueue<char> _queue);