#include <iostream>

namespace proj_A 
{
	class myNum 
	{
		public:
			int val1;
			int val2;
			int val3;

			myNum(int in1, int in2, int in3) 
			{
				val1 = in1;
				val2 = in2;
				val3 = in3;
			}
			int sum() 
			{
				return val1 + val2 + val3;
			}
			void print() 
			{
				printf("val1 = %d\n", val1);
				std::cout << "val2 = " << val2 << std::endl;
				std::cout << "val3 = " << val3 << std::endl;
				std::cout << "sum  = " << sum() << std::endl;
				std::cout << "dsize= " << sizeof(sum()) << std::endl;
			}
	};
}

namespace proj_B 
{
	class myNum 
	{
		public:
			int val1;
			int val2;
			int val3;

			myNum(int in1, int in2, int in3) 
			{
				val1 = in1;
				val2 = in2;
				val3 = in3;
			}
			int sum() 
			{
				return val1 + val2 + val3;
			}
			void print() 
			{
				printf("val1 = %d\n", val1);
				std::cout << "val2 = " << val2 << std::endl;
				std::cout << "val3 = " << val3 << std::endl;
				std::cout << "sum  = " << sum() << std::endl;
				std::cout << "dsize= " << sizeof(sum()) << std::endl;
			}
	};
}


void main() 
{	
	proj_A::myNum mynum1(1, 2, 3);
	proj_B::myNum mynum2(4, 5, 6);

	mynum1.print();
	mynum2.print();

	system("pause");
}
