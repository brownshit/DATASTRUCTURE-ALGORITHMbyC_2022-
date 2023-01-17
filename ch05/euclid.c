#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<string.h>
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}	

/*--유클리드 호제법--*/

int gcd(int x, int y) {		//x > y
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int main() {
	int x, y;
	puts("두 정수의 최대 공약수를 구합니다.");
	printf("int 1 input : "); scanf_s("%d", &x);
	printf("int 2 input : "); scanf_s("%d", &y);
	if (x < y) {
		int temp = x;
		x = y;
		y = temp;
	}
	printf("최대 공약수 : %d\n", gcd(x, y));

	return 0;
}
