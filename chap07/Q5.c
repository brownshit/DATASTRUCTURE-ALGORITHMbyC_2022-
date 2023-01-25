
#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

/*문자열 s에서 문자c 검색하는 함수.(선형검색...)*/
int* str_chr(const char* s, int c) {
	int i = 0;
	c = (char)c;
	while (s[i] != c) {
		if (s[i] == '\0') {
			return -1;		//검색 실패
		}
		i++;
	}
	return &s[i];		//검색 성공...index반환...
}

int main() {
	char str[128];
	char tmp[128];
	int ch;		//문자
	int* ptr;

	printf("문자열 : ");
	scanf_s("%s", str,sizeof(str));

	printf("검색할 문자 : ");
	scanf_s("%s", tmp,sizeof(tmp));
	ch = tmp[0];

	if ((ptr = str_chr(str, ch)) == -1)		//idx에 값도 할당함과 동시에 조건문 실행
		printf("문자 %c는 문자열에 없습니다.\n", ch);
	else
		printf("문자 %c 의 주소 %p\n", ch, ptr);

	return 0;
}
