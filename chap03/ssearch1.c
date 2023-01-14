#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		

int search(const int a[], int n, int key) {
	int i = 0;
	while(1) {
		if (a[i] == key)
			return i;
		else if (i == n)
			return -1;
		else
			i++;
	}
}

int main()
{	
	/*검색 알고리즘*/
	int nx, ky;
	puts("선형검색...\n");
	printf("요소개수 input : "); scanf_s("%d", &nx);
	
	int* x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		//data input...
		printf("x[%d] : ", i); scanf_s("%d", &x[i]);
	}

	printf("검색 값 : "); scanf_s("%d", &ky);	
	
	//this is indexs of key that you want to find
	int idx = search(x, nx, ky);
	printf("index of [%d] : %d", ky, idx);



	return 0;
}

/*
	
*/
