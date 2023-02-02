#include<stdio.h>
#include"Member.h"
#include"ChainHash.h"

/*메뉴*/
typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
}Menu;	//enum 자료형...

//정의한 열거형을 사용하려면 열거형 변수를 선언해야 합니다

// 열거형의 값은 처음에만 할당해주면 그 아래에 오는 값들은 1씩 증가하면서 자동으로 할당됩니다
// (아무 값도 할당하지 않으면 0부터 시작)

/*메뉴선택*/
Menu SelectMenu(void) {
	int ch;
	do {
		printf("(1) 추가 (2) 삭제 (3) 검색 (4) 모두삭제 (5) DUMP (0) 종료\n"); scanf_s("%d", &ch);
	} while (ch<TERMINATE || ch>DUMP);
	return (Menu)ch;
}

/*main function...*/
int main() {
	Menu menu;
	ChainHash hash;				//해시 테이블
	Initialize(&hash, 13);		//해시 테이블 초기화

	do {
		int result;
		Member x;
		Node* temp;

		switch (menu = SelectMenu()) {	//menu의 값에 의해 메뉴가 골라진다.
			//enum을 통해 문자열에 숫자를 할당하면 숫자에 의미를 담을수가 있다...!!
		case ADD:
			//INS_FRONT, 
				//아래의 구문이 굉장히 아름답다
			// sw == MEMBER_NO | MEMBER_NAME, 
			// (MEMBER_NO | MEMBER_NAME) & MEMBER_NO 는 (01 | 10) & 01
			x = ScanMember("추가", MEMBER_NO | MEMBER_NAME);
			result = Add(&hash, &x);
			if (result) {
				printf("\a[ERROR] : 추가에 실패하였습니다...(%s).\n",(result == 1) ? "이미 등록" : "메모리 부족");
			}
			continue;

		case DELETE:
			x = ScanMember("삭제", MEMBER_NO);
			result = Remove(&hash, &x);
			if (result == 1)
				printf("\a[ERROR] : 이 번호의 데이터가 존재하지 않습니다...\n");
			continue;

		case SEARCH:
			x = ScanMember("검색", MEMBER_NO);
			temp = Search(&hash, &x);
			if (temp == NULL) {
				printf("\a검색에 실패했습니다...\n");
			}
			else {
				printf("검색 성공!!...\n");
				PrintLnMember(&(temp->data));
			}
			continue;

		case  CLEAR:
			Clear(&hash);
			continue;

		case DUMP:
			Dump(&hash);
			continue;
		}
	} while (menu != TERMINATE);	// menu != 0이면 계속 실행
	Terminate(&hash);

	return 0;
}
