
#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>


//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type, x, y)do{type t = x; x = y; y = t; }while(0)      //run just 1 time

int int_cmp(const int* a, const int* b) {
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else return 0;
}

int main(void) {
	int nx;
	printf("qsort sorting...\n");
	printf("element number : "); scanf_s("%d", &nx);
	int* array = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("element [%d] input : ", i); scanf_s("%d", &array[i]);
	}

	//using qsort...
	qsort(array,											//배열
		nx,													//요소 개수	
		sizeof(int),										//요소 크기
		(int(*)(const void *, const void*))int_cmp			//비교함수...
		//비교함수는 두 인수의 비교를 진행, -1, 1, 0중의 하나의 값을 반환하는 func...
		);
	puts("오름차순 정렬 완료...");
	for (int i = 0; i < nx; i++) {
		printf("element [%d] : %d\n", i, array[i]);
	}

	free(array);
}
