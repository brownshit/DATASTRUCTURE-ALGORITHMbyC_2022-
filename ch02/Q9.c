#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<time.h>
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		

void shuffle(int a[], int n);

int main()
{	
	int arrSiz;
	srand(time(NULL));
	printf("arr size input : "); scanf_s("%d", &arrSiz);
	int* ARR = calloc(arrSiz, sizeof(int));
	puts("[input component...]");
	for (int i = 0; i < arrSiz; i++) {
		printf("comp [%d] : ", i + 1); scanf_s("%d", &ARR[i]);
	}
	puts("");
	for (int i = 0; i < arrSiz; i++) {
		printf("comp [%d] : %d\n", i + 1, ARR[i]);
	}
	printf("RUN shuffle...\n");
	puts("[RESULTS]\n");
	shuffle(ARR, arrSiz);
	for (int i = 0; i < arrSiz; i++) {
		printf("comp [%d] : %d\n", i + 1, ARR[i]);
	}
	free(ARR);
	return 0;
}

void shuffle(int a[], int n) {
	//n is comp num
	for (int i = 0; i < (n / 2); i++) {
		//call rand F
		int randVar_1 = rand() % n;
		int randVar_2 = rand() % n;
		int temp = a[randVar_1];
		a[randVar_1] = a[randVar_2];
		a[randVar_2] = temp;
	}
	//random shuffle... initializing by srand(time(NULL))
}
/*
	
*/
