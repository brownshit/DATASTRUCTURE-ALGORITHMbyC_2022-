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

static char memo[128][1024];		//메모용 전역 문자 변수

/*-- 메모제이션을 도입한 recur 함수 --*/
void recur(int n) {
	if (memo[n + 1][0] != '\0')		//메모가 되어있는 경우, n+1에 저장되어있는 메모를 출력		매크로의 역할을 한다!
		printf("%s", memo[n + 1]);
	else {							//메모가 되어있지 않다면 n+1자리에 메모를 작성한다.
		if (n > 0) {
			recur(n - 1);
			printf("%d\n", n);
			recur(n - 2);
			sprintf(memo[n+1], "%s%d\n%s",memo[n], n, memo[n-1]);
		}
		else {
			strcpy(memo[n + 1], "");
		}
	}
}

int main() {
	int n; printf("input number : "); scanf_s("%d", &n); printf("this is result of simuler recursive(using Stack...)\n"); recur(n);
	return 0;
}
