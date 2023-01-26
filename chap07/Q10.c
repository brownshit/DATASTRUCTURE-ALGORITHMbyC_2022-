#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

/*브루트 포스법을 이용한 문자열 검색함수*/
//브루트 포스법은 비효율적인 문자열 검색 알고리즘이다.
int bf_match(const char txt[], const char pat[]) {
	int pt = 0;		//txt 커서
	int pp = 0;		//pat 커서

	while (txt[pt] != '\0' && pat[pp] != '\0') {		//둘다 NULL이 아니면...
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else {
			//다음검색을 위한 준비
			pt = pt - pp + 1;		//다음검색의 커서... 넘어온 pp만큼 빼고 +1(for next step)
			pp = 0;
		}
	}
	if (pat[pp] == '\0') {
		return pt - pp;
	}
	return -1;	//검색실패
}

//reverse 브루트포스
int bf_matchr(const char txt[], const char pat[]) {
	int sizet = strlen(txt);
	printf("%d\n", sizet);
	int sizep = strlen(pat);

	int pt = sizet-1;		//txt 커서
	int pp = sizep-1;		//pat 커서

	while (pt>=0 && pp>=0) {		//둘다 NULL이 아니면...
		if (txt[pt] == pat[pp]) {
			pt--;
			pp--;
		}
		else {
			//다음검색을 위한 준비
			pt = pt - pp + 1;		//다음검색의 커서... 넘어온 pp만큼 빼고 +1(for next step)
			pp = sizep - 1;
		}
	}
	//마지막에 한번더
	if (pp<0) {
		return pt + sizep-1;
	}
	return -1;	//검색실패
}

int main() {
	char s1[256];
	char s2[256];
	puts("brute_force method...");
	puts("find pattern in text...");
	printf("text : "); scanf_s("%s", s1, sizeof(s1));
	printf("pattern : "); scanf_s("%s", s2, sizeof(s2));

	int idx = bf_matchr(s1, s2);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}
