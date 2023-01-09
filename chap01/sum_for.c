#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{	
	int n;
	puts("1~n sum...");
	printf("input n : ");
	scanf_s("%d",&n);

	int i, sum = 0;
	for (i = 0; i <= n; i++)
	{
		sum += i;
	}
	printf("this is sum of 1~%d : %d", n, sum);

	return 0;
}
