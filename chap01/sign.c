#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{	
	int n;
	printf("integer input ... ");
	scanf_s("%d", &n);
	if (n>0) {
		printf("%d is positive num...",n);
	}
	else if (n<0) {
		printf("%d is negative num...",n);
	}
	else {
		printf("%d is 0", n);
	}

	return 0;
}
