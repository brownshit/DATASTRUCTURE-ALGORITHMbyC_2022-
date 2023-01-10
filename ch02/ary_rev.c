#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
#define swap(type,x,y) {type t = x; x = y; y = t;}//do{type t = x; x = y; y = t; }while(0);

void arr_inverse(int a[], int n) {// this func change arr, so have not define arr to const!
	for (int i = 0; i < n/2; i++)		//해당 for 문은 n/2(둘다 정수라 몪만 반환된다.)만큼만 계산이 되어야 한다. n이 되면 원위치된다.
		swap(int, a[i], a[n - i - 1]);		//매크로 함수
}

int main()
{	
	int nx;
	printf("요소 개수 : ");
	scanf_s("%d", &nx);	//, sizeof(nx)
	int* x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ",i);
		scanf_s("%d", &x[i]);
	}
	arr_inverse(x, nx);		//make arr reverse!
	printf("array componants completly had changed into reverse arr !!\n");
	for (int i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}
	free(x);

	return 0;
}

/*
	
*/
