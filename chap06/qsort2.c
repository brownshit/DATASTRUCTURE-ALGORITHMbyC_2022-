//structure type data's sorting

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

typedef struct {
	char name[10];
	int hei;
	int wei;
}Person;

/*이름 오름차순*/
int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

/*키 오름차순*/
int hpcmp(const Person* x, const Person* y) {
	return x->hei < y->hei ? -1 :
		x->hei > y->hei ? 1 : 0;
}

/*몸무게 오름차순*/
int wpcmp(const Person* x, const Person* y) {
	return x->wei < y->wei ? -1 :
		x->wei > y->wei ? 1 : 0;
}

/*people data print*/
void print_person(const Person x[], int no) {
	for (int i = 0; i < no; i++)
		printf("%-10s %d[cm] %d[kg]\n", x[i].name, x[i].hei, x[i].wei);
}

int main(void) {
	Person arr[] = {
		{"sunmi", 170, 52},
		{"yoobin", 180, 70},
		{"sohee", 172, 63},
		{"jina", 165, 50}
	};

	int nx =sizeof(arr)/ sizeof(arr[0]);		//it means element number of array
	
	int* array = calloc(nx, sizeof(int));

	/*
		//using qsort...
	qsort(array,											//배열
		nx,													//요소 개수	
		sizeof(int),										//요소 크기
		(int(*)(const void *, const void*))int_cmp			//비교함수...
		//비교함수는 두 인수의 비교를 진행, -1, 1, 0중의 하나의 값을 반환하는 func...
		);

	*/

	//이름정렬
	qsort(arr, nx, sizeof(Person), (int(*)(const void*, const void*))npcmp);
	puts("[ 이름_정렬 ]");
	print_person(arr, nx);
	puts("\n");

	//키정렬
	qsort(arr, nx, sizeof(Person), (int(*)(const void*, const void*))hpcmp);
	puts("[ 키_정렬 ]");
	print_person(arr, nx);
	puts("\n");

	//몸무게정렬
	qsort(arr, nx, sizeof(Person), (int(*)(const void*, const void*))wpcmp);
	puts("[ 몸무게_정렬 ]");
	print_person(arr, nx);
	puts("\n");

	free(array);
	return 0;
}
