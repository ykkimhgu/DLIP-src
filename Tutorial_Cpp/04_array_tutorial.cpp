/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* Cpp Tutorial: Array
* Created: 2021-Spring
------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void printVec(double* _vec, int _row);

int main()
{
	// Static Matrix Allocation 1-D Array
	double a[4] = { 1, 2, 3, 4 };
	double b[] = { 2, 3, 4, 5 };
	double c[4] = { 0 };

	printVec(c, 4);
}


void printVec(double* _vec, int _row)
{
	for (int i = 0; i < _row; i++)
		printf("Vector[%d] = %f \n", i, _vec[i]);
	printf("\n");

}