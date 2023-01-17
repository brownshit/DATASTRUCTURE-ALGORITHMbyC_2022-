#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<string.h>
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}	


int factorial(int n) {
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main() {
	int x; printf("integer input : "); scanf_s("%d", &x);
	printf("%d's facorial result... : %d", x,factorial(x));

	return 0;
}
