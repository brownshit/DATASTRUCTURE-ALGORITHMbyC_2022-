#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<string.h>
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		

typedef struct {
	char name[10];
	int height;
	int weight;

}Person;

int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, (*y).name);	//->와 (*). 은 같은 연산이다.
}

int main() {
	//data must be sorting by ASCII number...
	Person x[] = {
		{"김영준", 179, 79},
		{"남아린", 163, 52},
		{"이예찬", 189, 85},
		{"진미연", 165, 55},
	};

	int nx = sizeof(x) / sizeof(x[0]);	//배열 x를 구성하는 요소개수
	int retry;

	puts(" searching by name...");
	do {
		puts("===========");
		for (int i = 0; i < nx; i++) {
			printf("%s\n", x[i].name);
		}
		puts("===========");
		Person temp;
		printf("name input : "); scanf_s("%s", temp.name, sizeof(temp.name));

		Person* p = bsearch(		//return type : element's pointer
			&temp,	//searching value's pointer.
			x,		//arr
			nx,		//arr	size
			sizeof(Person),		//ele size
			(int(*)(const void*, const void*))npcmp
		);
		if (p == NULL)
			puts("Searching Failed...");
		else {
			puts("lower element had found!");
			printf("x[%d] : %s %dcm %dkg\n",
				(int)(p - x), p->name, p->height, p->weight);
		}
		printf("wanna retry?\nyes[1]/no[0] : "); scanf_s("%d", &retry);

	} while (retry == 1);	//얘가 1이면 재실행.

	return 0;
}


/*
	for(;1;){
		//이것도 무한루프이다. while(1){ ... }같은.
	}
*/
