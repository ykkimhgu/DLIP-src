#ifndef _TU_DLIP_H		// same as "#if !define _TU_DLIP_H" (or #pragma once) 
#define _TU_DLIP_H

#include <iostream>

// =============================
// Exercise 1 :: Define Function
// =============================

int sum(int val1, int val2);


// ====================================
// Exercise 2 :: Create a Class ¡®myNum¡¯
// ====================================

class MyNum 
{
	public:
		MyNum(int x1, int x2);
		int val1;
		int val2;
		int sum(void);
		void print(void);
};

#endif // !_TU_DLIP_H