#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		


int main()
{	
	int prime[500];		//소수를 저장하는 배열.
	int ptr = 0;		//이미 얻은 소수의 개수.

	unsigned int counter = 0;//나눗셈 횟수

	prime[ptr++] = 2;	//2는 소수이기 때문.
	for (int i = 3; i <= 1000; i+=2) {//1은 소수도 합성수도 아님.즉, 반복 조건 제외.
		int j;
		for (j = 1; j < ptr; j++) {//ptr의 인덱스는 0에 2. 1부터 다시 재개해야 한다.
			counter++;
			if (i % prime[j] == 0) {//나누어 떨어지면 소수가 아님.
				break;
			}
		}
		if (j == ptr) {//마지막까지 나눠떨어지지 않으면 for 문 탈출시 ptr(소수 개수) == j(ptr까지의 소수개수)가 되어있다. _ j++때문에.
			prime[ptr++] = i;
		}
	}
	for (int i = 0; i < ptr; i++) {
		printf("%d\n", prime[i]);	//or i can be print
	}
	printf("나눗셈의 실행횟수 : %lu", counter);		//%lu??		long unsigned ( int )!!
	return 0;
}

/*
	
*/
