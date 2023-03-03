/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* Cpp Tutorial: Template
* Created: 2021-Spring
------------------------------------------------------*/

#include <iostream>

namespace proj_B {

	template<typename T>
	class myNum {
	public:
		T val1;
		T val2;
		T val3;

		myNum(T in1, T in2, T in3) {
			val1 = in1;
			val2 = in2;
			val3 = in3;
		}
		T sum() {
			return val1 + val2 + val3;
		}
		void print() {
			std::cout << "val1 = " << val1 << std::endl;
			std::cout << "val2 = " << val2 << std::endl;
			std::cout << "val3 = " << val3 << std::endl;
			std::cout << "sum  = " << sum() << std::endl;
		}
	};
}

int main(void) {
	
	proj_B::myNum<int> mynum1(10, 20, 30);
	proj_B::myNum<double> mynum2(0.1, 0.2, 0.3);
	
	mynum1.print();
	mynum2.print();

	return 0;
}