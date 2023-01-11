#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		


int main()
{	
	unsigned int counter = 0;//나눗셈 횟수
	for (int i = 2; i <= 1000; i++) {//1은 소수도 합성수도 아님.즉, 반복 조건 제외.
		int j;
		for (j = 2; j < i; j++) {
			counter++;
			if (i % j == 0) {//나누어 떨어지면 소수가 아님.
				break;
			}
		}
		if (j == i) {//마지막까지 나눠떨어지지 않으면 for 문 탈출시 j == i가 되어있다.
			printf("%d\n", j);	//or i can be print
		}
	}
	printf("나눗셈의 실행횟수 : %lu", counter);		//%lu??		long unsigned ( int )!!
	return 0;
}

/*
	
*/
