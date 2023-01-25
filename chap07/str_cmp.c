#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>


/* s1, s2비교함수 */
int str_cmp(const char* s1, const char* s2) {
	while (*s1 == *s2) {
		if (*s1 == '\0')		//s1이 끝까지 s2와 같으면 0반환
			return 0;
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}

int main() {
	char st[128];
	puts("\"ABCD\"와 비교합니다..."); puts("\"XXXX\"이면 종료합니다...");
	while (1) {
		printf("문자열 st : ");
		scanf_s("%s", st,sizeof(st));
		if (str_cmp("XXXX", st) == 0)
			break;
		printf("str_cmp(\"ABCD\", st) = %d\n", str_cmp("ABCD", st));
	}

	return 0;
}
