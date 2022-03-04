#include <iostream>

namespace proj_B {

	class myNum {
	public:
		int val1;
		int val2;
		int val3;

		myNum() {}
		myNum(int in1, int in2, int in3) {
			val1 = in1;
			val2 = in2;
			val3 = in3;
		}
		int sum() {
			return val1 + val2 + val3;
		}
		void print() {
			printf("val1 = %d\n", val1);
			std::cout << "val2 = " << val2 << std::endl;
			std::cout << "val3 = " << val3 << std::endl;
			std::cout << "sum  = " << sum() << std::endl;
			std::cout << "dsize= " << sizeof(sum()) << std::endl;
		}
	};
}


void main() {
	
	/// option 1
	//myNum mynum;
	//mynum.val1 = 10;
	//mynum.val2 = 20;

	/// option 2
	//proj_A::myNum mynum(11, 1100);
	proj_B::myNum mynum(11, 1100, 11);

	mynum.print();

	system("pause");
}
