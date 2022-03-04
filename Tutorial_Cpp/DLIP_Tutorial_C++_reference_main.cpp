///*------------------------------------------------------------------------------------------
//@ Deep Learning Image Processing  by Young-Keun Kim - Handong Global University
//
//
// Description     : Exercise:  C++ reference exercise
//------------------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

class MyNum {
public:
    MyNum() {};  	// Option 1 
    MyNum(int x); 	// Option 2     
    int num;
    double numinv();
};


// Class Constructor Definition 
MyNum::MyNum(int x)
{
    num = x;
}

double MyNum::numinv()
{
    // ADD CODE HERE
    // ADD CODE HERE
}


int main()
{

    // Option 1
    MyNum mynum;
    mynum.num = 10;

    // Option 2
    //MyNum mynum(10);


    cout << mynum.num << endl;
    // print its inverse value using  numinv() 
    // ADD CODE HERE

    return 0;
}
