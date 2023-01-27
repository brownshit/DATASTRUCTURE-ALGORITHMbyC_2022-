#include<stdio.h>
#include<string.h>
#include"Member.h"

/*회원번호 비교함수*/
int MemberNoCmp(const Member* x, const Member* y) {
	return x->no < y->no ? -1 :(x->no > y->no ? 1 : 0);
}

/*회원이름 비교함수*/
int MemberNameCmp(const Member* x, const Member* y){
	return strcmp(x->name, y->name);
}

/*회원데이터 출력*/
void PrintMember(const Member* x) {
	printf("%d %s", x->no, x->name);
}

/*회원데이터 출력_줄바꿈 있음*/
void PrintLnMember(const Member* x) {
	printf("%d, %s\n", x->no, x->name);
}

/*회원데이터를 읽음*/
Member ScanMember(const char* message, int sw) {
	Member temp;
	printf("%s 하는 데이터를 입력하세요...\n", message);
	if (sw & MEMBER_NO) { printf("번호 : "); scanf_s("%d", &temp.no); }
	if (sw & MEMBER_NAME) { printf("이름 : "); scanf_s("%s", temp.name, sizeof(temp.name)); }
	//no is integer but, name is pointer char(string)
}
