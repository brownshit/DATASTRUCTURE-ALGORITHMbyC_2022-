#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<math.h>

int main()
{	
	int n;
	do {
		printf("몇 단 삼각형입니까? : "); scanf_s("%d", &n);

	} while (n<=0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) { printf(" *"); }
		printf("\n");
	}
	printf("선물^^");
	return 0;
}

/*
	
*/
