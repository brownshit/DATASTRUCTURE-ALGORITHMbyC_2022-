#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{	
	int n;
	puts("1 ~ n sum oprator...");
	printf("n : ");
	scanf_s("%d", &n);

	int sum = 0;
	int i = 1;
	while (i <= n)
	{
		sum += i;
		i++;
	}
	printf("1 ~ %d sum : %d", n, sum);

	return 0;
}
