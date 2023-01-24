
#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

int main() {

	char st[8];
	st[0] = 'A';
	st[1] = 'B';
	st[2] = 'C';
	st[3] = 'D';
	st[4] = '\0';

	printf("string st에는 \" %s \"가 들어있습니다.\n", st);

	return 0;
}
