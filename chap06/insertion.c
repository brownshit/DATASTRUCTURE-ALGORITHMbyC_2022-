#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//	_CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<string.h>
//#include<time.h>

//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
#define swap(type, x, y)do{type t = x; x = y; y = t; }while(0)		//run just 1 time

void insertion(int a[],int n) {
	for (int i = 1; i < n; i++) {
		int temp = a[i];
		int j;
		for (j = i; j > 0 && a[j - 1] > temp; j--) {	// j > 0 && a[j - 1] 인 경우 계속 반복. 드모르간의 법칙 적용
			a[j] = a[j - 1];
		}//반복이 끝나면, 즉, j == 0 or temp가 더 크게 된 경우 종료.
		a[j] = temp;
		//insertion	ends...
	}
}

int is_sorted(const int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1])
			return 0;
	}
	return 1;
}

int main() {
	int nx;
	puts("insertion_sorting...");
IDX:
	printf("element num input : "); scanf_s("%d", &nx);

	int* array = calloc(nx, sizeof(int));		//size, data_type

	for (int i = 0; i < nx; i++) {
		printf("element[%d]input : ", i); scanf_s("%d", &array[i]);
	}

	insertion(array, nx);
	
	//정렬 상태 검사...
	if (is_sorted == 0) {
		printf("code is not sorted yet...");
		free(array);
		goto IDX;
	}
	else {
		puts("asending order sorting complete...!!");
	}
	//print array...
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, array[i]);

	free(array);	//free stack memory by dynamic allocation
	return 0;


	return 0;
}
