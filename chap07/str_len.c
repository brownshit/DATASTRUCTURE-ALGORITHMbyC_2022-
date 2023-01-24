#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

int str_len(const char* s) {
	int len = 0;
	while (s[len])	//s[len ] == NULL이 되면 while  문 종료,,, ++없이...
		len++;
	return len;		//그래서 길이가 반환된다,
}

int str_len_2(const char* s) {
	int len = 0;
	while (*s++)	//인덱스로서 len사용하지 않고 s의 인덱스를 하나씩 증가시켜간다.
		len++;
	return len;		//그래서 길이가 반환된다,
}

int main() {
	char str[256];
	printf("문자열 : "); scanf_s("%s", str, sizeof(str));		//sizeof(포인터 변수) 가 인수로 추가로 더 들어가야 하는게 옳은 형식,,,
	printf("%s\n", str);
	printf("문자열 길이(1) : %d\n", str_len(str));
  printf("문자열 길이(2) : %d\n", str_len_2(str));



	return 0;
}
