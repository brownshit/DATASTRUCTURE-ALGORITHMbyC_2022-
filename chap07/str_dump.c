#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

/*문자열 s안의 문자를 16진수와 2진수로 출력하는 함수*/
void str_dump(const char* s) {
	for (; *s != '\0'; s++) {	//s는 인자로 받아오기 때문에 initialization이 필요 없다.

		printf("%c %0*X ",*s,(CHAR_BIT+3)/4, *s);	//문자와 16진수 표현
		
		//2진수 표현
		for (int i = CHAR_BIT - 1; i >= 0; i--)
			putchar(((*s >> i) & 1U) ? '1' : '0');
		/*
		1U  == (unsigned int) 1
		*/
		putchar('\n');
	}
}

int main() {

	str_dump("STRING");
	return 0;
}
