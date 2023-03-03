#include "TU_DLIP.h"

#include <iostream>

// =============================
// Exercise 1 :: Define Function
// =============================

int sum(int val1, int val2)
{
	int out = val1 + val2;

	return out;
}

// ====================================
// Exercise 2 :: Create a Class ¡®myNum¡¯
// ====================================

MyNum::MyNum(int x1, int x2)
{
	val1 = x1;
	val2 = x2;
}

int MyNum::sum(void)
{
	int out = val1 + val2;

	return out;
}

void MyNum::print(void)
{
	std::cout << "MyNum.val1 :: " << val1 << std::endl;
	std::cout << "MyNum.val2 :: " << val2 << std::endl;
	std::cout << "Sum : " << sum() << std::endl;
}










