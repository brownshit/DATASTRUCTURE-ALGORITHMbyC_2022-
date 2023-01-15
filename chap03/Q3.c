#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		

int search_idx(const int a[], int n, int k, int idx[]) {
	int numofkey = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == k) {
			idx[numofkey] = i;
			numofkey++;
		}
	}
	return numofkey;
}


int main()
{	
	/*검색 알고리즘*/
	int nx, ky,numofk;
	puts("binary search...\n");
	printf("comp num input : "); scanf_s("%d", &nx);
	int* x = calloc(nx, sizeof(int));
	int* idx = calloc(nx, sizeof(int));		//찾는 배열의 인덱스 배열.

	//data input.
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf_s("%d", &x[i]);
	}

	do {
		printf("input key that you wnat to find : "); scanf_s("%d", &ky);

		//get idx arr and num
		numofk = search_idx(x, nx, ky, idx);

		if (numofk != 0) {
			printf("num of key that you want : %d\nindex array..[ ",numofk);
			for (int i = 0; i < numofk; i++) {
				printf(" %d ", idx[i]);
			}
			printf("]");
		}
		else {
			printf("there are no %d in arr x...\n[retry]", ky);
		}
	} while (numofk==0);

	free(idx);
	free(x);
	return 0;
}

/*
	for(;1;){
		//이것도 무한루프이다. while(1){ ... }같은.
	}
*/
