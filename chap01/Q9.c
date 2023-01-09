#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int sumof(int a, int b) {
	int suma = 0,sumb = 0, sum = 0;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i = 0; i <= b; i++) { sumb += i; }
	for (int j = 0; j < a; j++) { suma += j; }
	sum = sumb - suma;
	return sum;
}
int main()
{	
	int a, b;
	printf("input a,b by blank... : ");
	scanf_s("%d %d", &a, &b);

	printf("sum between a and b : %d", sumof(a,b));

	return 0;
}

/*

*/
