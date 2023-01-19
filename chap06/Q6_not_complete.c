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

void bubble(int a[], int n) {
	int k = 0;		//a[k]보다 앞 요소는 정렬이 끝난 상태
	//add parameter for shaker sort...
	int shake_param = 1;
	while (k < n - 1) {
		/*
			쉐이커정렬
			홀수번째 pass : 가장 작은 요소를 맨 앞으로 옮긴다.
			짝수번째 pass : 가장 큰 요소를 맨 뒤로 옮긴다.
		*/
		if (shake_param % 2 == 1) {
			int last = n - 1;
			for (int j = n - 1; j > k; j--)
				if (a[j - 1] > a[j]) {
					swap(int, a[j - 1], a[j]);
					last = j;
				}
			k = last;
		}
		else {
			int front = 0;
			for (int j = k; j < n - 1; j++) {
				if (a[j] < a[j + 1]) {
					swap(int, a[j], a[j+1]);
					front = j;
				}
			}
			k = front;
		}
		shake_param++;
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
	puts("bubble_sorting...");
IDX:
	printf("element num input : "); scanf_s("%d", &nx);

	int* array = calloc(nx, sizeof(int));		//size, data_type

	for (int i = 0; i < nx; i++) {
		printf("element[%d]input : ", i); scanf_s("%d", &array[i]);
	}

	bubble(array, nx);
	
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
