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

//divide a into group
void partition(int a[], int n) {
	int pl = 0;
	int pr = n - 1;
	int pivot = a[n / 2];		//pivot..!
	do {
		while (a[pl] < pivot) pl++;		//pl>=pivot인경우 종료
		while (a[pr] > pivot) pr--;		//pr<=pivot인경우 종료
		//swap condition
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++; pr--;		//		+=1
		}
	} while (pl<=pr);		//pl이 pr보다 크면 반복종료...
	puts("[partition]============================================");
	printf("[pivot] : %d\n", a[pivot]);
	printf("[under pivot group] : ");
	for (int i = 0; i <= pl - 1; i++) {//pl-1 == pivot...!
		printf("%d ", a[i]);
	}
	putchar('\n');
	printf("[[pivot group]] : ");
	for (int i = pr + 1; i <= pl - 1; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');
	printf("[over pivot group] : ");
	for (int i = pr+1; i < n; i++) {//pl-1 == pivot...!
		printf("%d ", a[i]);
	}
	putchar('\n');
	puts("=======================================================");
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
	puts("quick_sorting...");
IDX:
	printf("element num input : "); scanf_s("%d", &nx);

	int* array = calloc(nx, sizeof(int));		//size, data_type

	for (int i = 0; i < nx; i++) {
		printf("element[%d]input : ", i); scanf_s("%d", &array[i]);
	}

	partition(array, nx);
	
	/*
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

	*/
	free(array);	//free stack memory by dynamic allocation
	return 0;


	return 0;
}
