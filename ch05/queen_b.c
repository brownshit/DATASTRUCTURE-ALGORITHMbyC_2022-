#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//	_CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<string.h>
//#include<time.h>

//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}	

int pos[8];		//각 열에서 퀸의 위치

void print() {
	for (int i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

void set(int i) {
	for (int j = 0; j < 8; j++) {
		pos[i] = j;
		if (i == 7)
			print();
		else
			set(i + 1);
	}
}

int main() {
	set(0);//0열에 퀸을 배치

	return 0;
}
