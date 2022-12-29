#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{	
	int n;
	printf("integer input ... ");
	scanf_s("%d", &n);
	if (n == 1) {
		puts("A");
	}
	else if (n == 2) {
		puts("B");	//printf("B"); 와 같은 구문인가? puts...?
	}
	else if(n == 3) {
		puts("C");
	}

	return 0;
}
