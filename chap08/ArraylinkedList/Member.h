//#pragma once
#ifndef  ___Member
#define	 ___Member

//this header...10_1
typedef struct {
	int no;
	char name[20];
}Member;

#define MEMBER_NO 1		//번호 나타내는 정수값
#define MEMBER_NAME 2	//이름을 나타내는 정수 값

/*회원번호 비교함수*/
int MemberNoCmp(const Member* x, const Member* y);

/*회원이름 비교함수*/
int MemberNameCmp(const Member* x, const Member* y);

/*회원데이터 출력*/
void PrintMember(const Member* x);

/*회원데이터 출력_줄바꿈 있음*/
void PrintLnMember(const Member* x);

/*회원데이터를 읽음*/
Member ScanMember(const char* message, int sw);

#endif // ! ___Member
