#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		

//보초법 이용 search.
int bin_search(const int a[], int n, int k) {//이 알고리즘은 arr의 변형이 있기에 const없다.
	int pl = 0; int pr = n - 1;		//pivot left, pivot right
	do {
		int pc = (pl + pr) / 2;		//pivot center
		if (a[pc] == k) {
			return pc;		//return pc by index what you wanted
		}
		else if (a[pc] > k)
			pr = pc - 1;
		else
			pl = pc + 1;
	} while (pl <= pr);		//pl 이 pr보다 크게 되면 do~while ends
	return -1;		//검색 실패 반환값.


}


int main()
{	
	/*검색 알고리즘*/
	int nx, ky;
	puts("binary search...\n");
	printf("comp num input : "); scanf_s("%d", &nx);
	int* x = calloc(nx, sizeof(int));

	printf("x[0]: "); scanf_s("%d", &x[0]);

	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d]: ", i); scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);			//만약 오름차순 입력이 아니라면 재입력을 하게되는 구문.
	}

	int idx = 0;

	do {
		printf("검색 값 : "); scanf_s("%d", &ky);

		//this is indexs of key that you want to find
		idx = bin_search(x, nx, ky);
		if (idx != -1)
			printf("[ Result ]...index of [%d] : %d", ky, idx);
		else {
			printf("\n[binary searching failed...please input Again]\n");
		}

	} while (idx == -1);

	free(x);
	return 0;
}

/*
	for(;1;){
		//이것도 무한루프이다. while(1){ ... }같은.
	}
*/
