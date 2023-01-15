#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		

int int_cmp(const int* a, const int* b);

//bsearch is in stdlib.h header file.

int main()
{	
	/*검색 알고리즘*/
	int nx, ky;
	puts("Use bsearch to searching...\n");
	printf("comp num input : "); scanf_s("%d", &nx);
	int* x = calloc(nx, sizeof(int));

	//data input.
	for (int i = 0; i < nx; i++) {
		do {
			printf("x[%d]: ", i); scanf_s("%d", &x[i]);
		} while (x[i]< x[i-1]);
	}
	printf("key value input : "); scanf_s(" % d", ky);
	
	
	/*--using bsearch function--*/
		//pointer type data output...
	int* p = bserch(
		&ky,		//검색값에 대한 포인터
		x,			//array
		nx,			//array len
		sizeof(int),//array element size
		(int(*)(const void *, const void *))int_cmp		//비교함수... 일단 함수와의 관계를 잘 살펴보자.
		);
	//bsearch 의 반환형은 찾으려는 요소의 포인터 변수인 것에 유의 할것!
	

	if (p == NULL)
		puts("Searching Failed...");
	else
		printf("%d is in x[%d]", ky,(int)(p-x));	//p-x 는 해당위치의 주소값에서 x의 주소값을 빼고 난 후의 주소값을 int로 casting한것이다.

	free(x);
	return 0;
}


int int_cmp(const int* a, const int* b) {
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;		//compare by memory...
}


/*
	for(;1;){
		//이것도 무한루프이다. while(1){ ... }같은.
	}
*/
