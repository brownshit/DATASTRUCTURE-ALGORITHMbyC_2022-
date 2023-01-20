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

//이 쉡은 h가 121 -> 40 -> 13 -> 4 -> 1 이렇게... 겹치는 것 업이 무의미한 교환을 최소화하기 위해,,,
  //most interesting way of shell sorting

void shell(int a[],int n) {
	int h;
	for (h = 1; h < n; h = h * 3 + 1)
		;	//n보다 작은 최대한의 h를 만들어놓기 위한 for
	for (; h > 0; h /= 3) {
		for (int i = h; i < n; i++) {
			int temp = a[i];
			int j;
			for (j = i - h; j >= 0 && a[j] > temp; j -= h) {
				a[j + h] = a[j];
			}
			a[j + h] = temp;
		}
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
	puts("shell_sorting...");
IDX:
	printf("element num input : "); scanf_s("%d", &nx);

	int* array = calloc(nx, sizeof(int));		//size, data_type

	for (int i = 0; i < nx; i++) {
		printf("element[%d]input : ", i); scanf_s("%d", &array[i]);
	}

	shell(array, nx);
	
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
