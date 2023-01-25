
#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

int main() {
	char st[128];
	puts("\"STRING\"과 처음 3개문자를 비교합니다..."); puts("\"XXXX\"이면 종료합니다...");
	while (1) {
		printf("문자열 st : ");
		scanf_s("%s", st,sizeof(st));
		if (strncmp("XXXX", st,4) == 0)
			break;
		//strncmp함수는 -1, 0, 1 중에 하나의 값만을 반환한다.
		printf("strncmp(\"STRING\", st) = %d\n", strncmp("STRING", st,3));
	}

	return 0;
}
