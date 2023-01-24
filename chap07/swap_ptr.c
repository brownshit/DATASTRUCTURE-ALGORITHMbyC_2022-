
#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

void swap_ptr(char** x, char** y) {
	char* tmp = *x;
	*x = *y;
	*y = tmp;
}

int main() {
	char* s1 = "ABCD";
	char* s2 = "EFGH";

	printf("포인터 s1은 %s를 가리킵니다.\n", s1);
	printf("포인터 s2은 %s를 가리킵니다.\n", s2);

	swap_ptr(&s1, &s2);

	puts("[교환 완료...]");

	printf("포인터 s1은 %s를 가리킵니다.\n", s1);
	printf("포인터 s2은 %s를 가리킵니다.\n", s2);

	return 0;
}
