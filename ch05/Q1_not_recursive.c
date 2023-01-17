#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<string.h>
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}	

int factorial(int x) {
	int fac_num = x, total_fac = 1;
	while (1) {
		if (fac_num == 1)
			break;
		else{
			total_fac *= fac_num;
			fac_num--;
		}
	}
	return total_fac;
}

int main() {
	int n;
	printf("input int to run factorial program...\n");
	printf("[input] : "); scanf_s("%d", &n);
	printf("result of %d 's facorial operation : %d\n", n, factorial(n));

	return 0;
}
