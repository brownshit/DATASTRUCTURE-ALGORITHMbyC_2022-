#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
#define swap(type, x,y)do{type t = x; x = y; y = t;}while(0)
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		
//여기서는 while뒤에 세미콜론 없다. 아래에서 함수 호출시 세미콜론이 있기 때문. 매크로 함수는 그대로 들어간다고 생각하고 이상하면 오류가 나는것.

//정수x를 n진수로 변환한 숫자문자의 정렬을 d에 저장.
int card_conv(unsigned x, int n, char d[]) {//char *d와 같다.		condition : x >= 0
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;			//변환후 자릿수

	if (x == 0)
		d[digits++] = dchar[0];
	else {
		while (x) {		//x가 0아니면 무한 루프
			//x/n의 나머지를 자리수에 두고 몪은 다시 x가 가져가서 몪이 0이 될때까지 반복하기 위함...
			d[digits++] = dchar[x % n];
			x /= n;
		}
	}
	for (int i = 0; i < (digits / 2); i++) {		//여기 n이 아니라 digits 인것에 주의하자.
		swap(char, d[i], d[digits - 1 - i]);
		//역순 정리를 해서 MSB와 LSB를 바꿔준다.
	}

	return digits;
}
int main()
{	
	puts("[10진수의 기수변환]...");		//자동 개행
	int retry;		//재실행을 위한.
	do {
		unsigned	no;			//unsigned int == unsigned 로 축약해서 사용하기도 한다.
		int			cd;			//기수
		char		cno[512];	//변환한 값의 각 자리 숫자를 저장하는 문자 배열...

		printf("변환할 정수 input : "); scanf_s("%u", &no);		//%u : unsigned int 의 escape chr
		do {
			printf("진수 입력 [2 ~ 36]: "); scanf_s("%d", &cd);
		} while (cd<2 || cd>36);//드모르간 법칙 ...		!(cd>=2 && cd<=36) 로 변경가능

		int dno = card_conv(no, cd, cno);		//dho는 cno의 자리수이다... 배열의 자릿수는 c에서 중요하다! ... 인덱싱

		printf("convert to %d 진수 : ", cd);
		for (int i =0; i<dno;i ++){
			printf("%c", cno[i]);
		}
		puts("");

		printf("재실행 할까요?...to be continue, input '1'... : "); scanf_s("%d", &retry);
		*cno = NULL;
	} while (retry == 1);
	
	return 0;
}

/*
	
*/
