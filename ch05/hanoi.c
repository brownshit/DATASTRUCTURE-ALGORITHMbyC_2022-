#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<string.h>
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}	


/*--원반 [1] ~ 원반 [no]를 기둥 x에서 기둥 y로 옮김--*/
void move(int no, int x, int y) {
	if (no > 1)
		move(no - 1, x, 6 - x - y);
	printf("원반[%d]를 %d기둥에서 %d기둥으로 오림김\n", no, x, y);
	if (no > 1)
		move(no - 1, 6 - x - y, y);
}

int main() {
	int n;
	printf("하노이의 탑 \n원반개수 : "); scanf_s("%d", &n);
	move(n, 1, 3);


	return 0;
}
