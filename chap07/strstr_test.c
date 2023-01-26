#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

int main() {
	char s1[256], s2[256];
	puts("strstr function...");
	printf("text : "); scanf_s("%s", s1,sizeof(s1));
	printf("pattern : "); scanf_s("%s", s2, sizeof(s2));

	char* p = strstr(s1, s2);
	if (p == NULL)
		printf("there is no pattern in text...\a\n");
	else {
		int ofs = p - s1;
		printf("\n%s\n", s1);
		printf("%*s|\n", ofs,"");
		printf("%*s%s\n", ofs,"",s2);

	}
	return 0;
}
