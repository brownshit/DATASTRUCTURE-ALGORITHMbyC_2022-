#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		

//보초법 이용 search.
int search(int a[], int n, int k) {//이 알고리즘은 arr의 변형이 있기에 const없다.
	int i = 0; 
	
	//보초를 추가
	a[n] = k;		//append( put value into last ele.) element in array...
	while (1) {
		if (a[i] == k)
			break;
		i++;
	}
	return (i == k) ? -1 : i;		//삼항 논리 연산자의 매우 적절한 사용...
}


int main()
{	
	/*검색 알고리즘*/
	//보초법을 통해 종료조건의 검사시간을 50프로 단축가능.
	//마지막 요소 한칸뒤에 찾는 요소를 추가시켜 key value와 array index 가 같은 경우를 검사하는데 이때, 추가된 마지막 요소라면 검색실패인 alg
	int nx, ky;
	puts("linear search(보초법을 곁들인,,,)");
	printf("comp num input : "); scanf_s("%d", &nx);
	int* x = calloc(nx+1, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf_s("%d", &x[i]);
	}

	printf("검색 값 : "); scanf_s("%d", &ky);

	//this is indexs of key that you want to find
	int idx = search(x, nx, ky);
	printf("index of [%d] : %d", ky, idx);



	free(x);
	return 0;
}

/*
	for(;1;){
		//이것도 무한루프이다. while(1){ ... }같은.
	}
*/
