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

void new_bubble(int a[], int n) {
	for (int i = 0; i < n-1 ; i++) {
		int exchg = 0;		//하나의 pass에서의 교환횟수
		for (int j = n-1; j > 0; j--)
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		if (exchg == 0)	break;	//더이상의교환이 일어나지 않는다면!
	}
}

int main() {
	int nx;
	puts("bubble_sorting...");
	printf("element num input : "); scanf_s("%d", &nx);

	int* array = calloc(nx, sizeof(int));		//size, data_type

	for (int i = 0; i < nx; i++) {
		printf("element[%d]input : ", i); scanf_s("%d", &array[i]);
	}

	new_bubble(array, nx);
	puts("asending order sorting complete...!!");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, array[i]);

	free(array);	//free stack memory by dynamic allocation
	return 0;


	return 0;
}
