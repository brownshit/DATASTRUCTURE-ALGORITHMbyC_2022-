#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#define N 5
int main()
{	
	int a[N] = {1,2,3,4,5};
	int na = sizeof(a) / sizeof(a[0]);		//	/sizeof(int)도 똑같다.
	printf("배열 a의 요소 개수 : %d\n", na);

	for (int i = 0; i < na; i++)
		printf("a[%d] = % 3d\n",i,a[i]);
	return 0;
}

/*
	
*/
