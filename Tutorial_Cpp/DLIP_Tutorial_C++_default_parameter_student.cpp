
#include <iostream>

namespace proj_B
{
	template<typename T>
	class myNum
	{
	public:
		T val1;
		T val2;
		T val3;
		T sumVal;

		myNum(T in1, T in2, T in3)
		{
			val1 = in1;
			val2 = in2;
			val3 = in3;
		}

		// ADD CODE HERE 
		// SET THIRD INPUT PARAMETER AS 0 (DEFAULT PARAMETER)

		void print(void)
		{
			std::cout << "val1 = " << val1 << std::endl;
			std::cout << "val2 = " << val2 << std::endl;
			std::cout << "val3 = " << val3 << std::endl;
			std::cout << "sum  = " << sumVal << std::endl;
		}
	};
}

int main(void)
{
	proj_B::myNum<int> mynum1(1, 2, 3);
	proj_B::myNum<int> mynum2(1, 2, 3);

	mynum1.sum(1, 2, 3);
	mynum2.sum(1, 2);

	mynum1.print(); // expected result: 1 + 2 + 3 + 1 + 2 + 3 = 12
	mynum2.print(); // expected result: 1 + 2 + 3 + 1 + 2 + 0(default) = 9

	return 0;
}