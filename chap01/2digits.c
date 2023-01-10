#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<math.h>

int main()
{	
	int no;
	printf("digit2  int input...\n"); 
	do {
		printf("num :");
		scanf_s("%d", &no);

	} while (no<10 ||no>99);	//while 내부 조건에 부합하면 반복한다. 아니면 escape.
	printf("no is : %d\n", no);
	
	return 0;
}

/*
	
*/
