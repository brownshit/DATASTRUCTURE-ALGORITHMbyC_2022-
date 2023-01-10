#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>		//for malloc and free


int main()
{	
	int a, b;
	printf("a value : "); scanf_s("%d", &a);
	do {
		printf("b value : "); scanf_s("%d", &b);
	} while (b<=a);	//in b<=a condition, "while" is work...!
	printf("b-a = %d\n", b-a);

	
	return 0;
}

/*
	printf는 개행을 따로 써주지 않으면 하지 않는다.
	puts는 개행을 따로 써주지 않아도 알아서 문장이 끝나면 개행을 한다.


*/
