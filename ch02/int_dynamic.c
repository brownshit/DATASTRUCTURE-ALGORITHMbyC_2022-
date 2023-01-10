#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

int main()
{	
	//동적할당.
	int* x = calloc(1, sizeof(int));
	//int 형 포인터에 메모리 할당.

	if (x == NULL) {
		puts("메모리 할당 실패.");
	}
	else {
		*x = 57;//x 의 value에 57 대입연산.		x는 변수가 아니라 공간.
		printf("*x = %d\n", *x);//value
		free(x);
	}

	return 0;
}

/*
	
*/
