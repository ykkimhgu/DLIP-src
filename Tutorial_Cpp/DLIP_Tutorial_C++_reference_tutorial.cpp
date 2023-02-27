/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* Cpp Tutorial: Reference
* Created: 2021-Spring
------------------------------------------------------*/

#include <stdio.h>

void swap(int* a, int* b);

int main()
{
	int val1 = 10;
	int val2 = 20;

	printf("Before SWAP operation \n");
	printf("val1 : %d \n", val1);
	printf("val2 : %d \n\n", val2);

	swap(&val1, &val2);

	printf("After SAWP operation \n");
	printf("val1 : %d \n", val1);
	printf("val2 : %d \n\n", val2);

	return 0;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}