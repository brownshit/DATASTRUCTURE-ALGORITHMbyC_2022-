#include<stdio.h>
#include"Member.h"
#include"CircDbLinkedList.h"

/*메뉴*/
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, NEXT, PREV, CLEAR
}Menu;	//enum 자료형...

//정의한 열거형을 사용하려면 열거형 변수를 선언해야 합니다

// 열거형의 값은 처음에만 할당해주면 그 아래에 오는 값들은 1씩 증가하면서 자동으로 할당됩니다
// (아무 값도 할당하지 않으면 0부터 시작)

/*메뉴선택*/
Menu SelectMenu(void) {
	int ch;
	char* mstring[] = {
		"머리에 노드 삽입",	"꼬리에 노드삽입",		"머리 노드를 삭제",
		"꼬리 노드를 삭제",	"선택한 노드를 출력",	"선택한 노드를 삭제",
		"번호로 검색",		"이름으로 검색",		"모든 노드를 출력",
		"선택한 노드를 뒤쪽으로","선택한 노드를 앞쪽으로","모든 노드를 삭제",
	};	//이중 포인터, 이중 배열과 비슷한맥락.(하나의 요소가 문자열.)

	do {
		for (int i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-22.22s ", i + 1, mstring[i]);
			if ((i % 3) == 2)		//한번에 메뉴 3개씩만 띄운다.
				putchar('\n');
		}
		printf("(0)종료 : "); scanf_s("%d", &ch);
	} while (ch<TERMINATE || ch>CLEAR);
	return (Menu)ch;	//input ch를 Menu enum type로 casting하여서...
}

/*main function...*/
int main() {
	Menu menu;
	Dlist list;
	Initialize(&list);	//전체 리스트 크기가 30인것,,,(프리 리스트 크기까지 포함해서...)

	do {
		Member x;
		switch (menu = SelectMenu()) {	//menu의 값에 의해 메뉴가 골라진다.
			//enum을 통해 문자열에 숫자를 할당하면 숫자에 의미를 담을수가 있다...!!
		case INS_FRONT:
			//INS_FRONT, 
				//아래의 구문이 굉장히 아름다움
			x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
			// sw == MEMBER_NO | MEMBER_NAME, 
			// (MEMBER_NO | MEMBER_NAME) & MEMBER_NO 는 (01 | 10) & 01
			InsertFront(&list, &x);
			break;

		case INS_REAR:
			//INS_REAR,
			x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;

		case RMV_FRONT:
			//RMV_FRONT,
			RemoveFront(&list);
			break;

		case  RMV_REAR:
			//RMV_REAR,
			RemoveRear(&list);
			break;

		case PRINT_CRNT:
			//PRINT_CRNT,
			PrintLnCurrent(&list);
			break;

		case RMV_CRNT:
			//RMV_CRNT,
			RemoveCurrent(&list);
			break;

			//번호로 검색
		case SRCH_NO:
			//SRCH_NO,
			x = ScanMember("검색(번호)", MEMBER_NO);
			if (Search(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("해당번호 데이터는 없음...");
			break;

		case  SRCH_NAME:
			//SRCH_NAME,
			x = ScanMember("검색(이름)", MEMBER_NAME);
			if (Search(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("해당이름 데이터는 없음...");
			break;

		case PRINT_ALL:
			//PRINT_ALL, 
			Print(&list);
			break;

		case NEXT:
			Next(&list);
			break;

		case PREV:
			Prev(&list);
			break;

		case CLEAR:
			//CLEAR
			Clear(&list);
			break;
		}
	} while (menu != TERMINATE);	// menu != 0이면 계속 실행
	Terminate(&list);

	return 0;
}
