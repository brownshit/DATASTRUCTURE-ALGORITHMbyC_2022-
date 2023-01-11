#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		


int main()
{	
	int prime[500];
	int ptr = 0;
	unsigned long counter = 0;
	prime[ptr++] = 2;
	prime[ptr++] = 3;
	for (int i = 5; i < 1000; i += 2) {//홀수만을 대상으로 한다.
		int j;
		int flag = 0;	//default
		for (int j = 1; counter++, prime[j] * prime[j] <= i; j++) {	//이와같이 종료 조건안에 ; , ; 쉼표를 이용 연산을 추가할 수 있다.
			counter++;												//counter++가 2개인 이유 : 각 연산 (곱셈, 나눗셈)의 연산수의 총합 계산. 
			if (i % prime[j] == 0) {		//나누어 떨어지게 되면.
				flag = 1;
				break;		//더이상의 반복은 불필요.
			}
		}
		if (!flag) {//flag 가 종료조건까지 0을 유지한 경우
			prime[ptr++] = i;
		}
	}
	for (int i = 0; i < ptr; i++) {
		printf("%d\n", prime[i]);
	}
	printf("곱셈과 나눗셈을 실행한 횟수.(알고리즘의 속도를 파악위해. 각 연산은 연산속도 비례.) : %d", counter);


	return 0;
}

/*
	
*/
