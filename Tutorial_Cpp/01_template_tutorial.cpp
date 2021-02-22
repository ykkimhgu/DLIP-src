/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* Cpp Tutorial: Template
* Created: 2021-Spring
------------------------------------------------------*/

#include <iostream>

using namespace std;

template<typename T>
class Data
{
	T data;
public:
	Data(T d) {
		data = d;
	}
	void SetData(T d) {
		data = d;
	}
	T GetData() {
		return data;
	}
};

int main(void) {
	Data<int> d1(0);
	d1.SetData(10);
	Data<char> d2('c');

	cout << d1.GetData() << endl;
	cout << d2.GetData() << endl;

	return 0;
}