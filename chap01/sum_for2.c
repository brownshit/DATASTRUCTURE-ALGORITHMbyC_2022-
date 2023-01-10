#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>		//for malloc and free


int main()
{	
	int n;
	puts("1~n sum...");
	
	do {
		//n<=0인 경우에 대해서 반복이 된다. do while 사이의 명령문을 먼저 실행 한 후.
		printf("input n : ");
		scanf_s("%d", &n);
	} while (n <= 0);		//to get n upper than 0...

	int sum = 0;
	for (int i = 1; i <= n; i++) { sum += i; }
	printf("1~%d 's sum : %d", n, sum);

	return 0;
}

/*

*/
