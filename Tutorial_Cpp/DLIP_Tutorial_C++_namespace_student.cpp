#include <iostream>

namespace proj_A
{
	// Add code here
}

namespace proj_B
{
	// Add code here
}


void main()
{
	proj_A::myNum mynum1(1, 2, 3);
	proj_B::myNum mynum2(4, 5, 6);

	mynum1.print();
	mynum2.print();

	system("pause");
}
