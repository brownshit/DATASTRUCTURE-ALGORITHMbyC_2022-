#include<stdio.h>
#include"Member.h"
#include"BinTree.h"

/*메뉴*/
typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, PRINT
}Menu;	//enum 자료형...

//정의한 열거형을 사용하려면 열거형 변수를 선언해야 합니다

// 열거형의 값은 처음에만 할당해주면 그 아래에 오는 값들은 1씩 증가하면서 자동으로 할당됩니다
// (아무 값도 할당하지 않으면 0부터 시작)

/*메뉴선택*/
Menu SelectMenu(void) {
	int ch;
	do {
		printf("(1) 삽입 (2) 삭제 (3) 검색 (4) 출력 (0) 종료\n"); scanf_s("%d", &ch);
	} while (ch<TERMINATE || ch>PRINT);
	return (Menu)ch;
}

/*main function...*/
int main() {
	Menu menu;
	BinNode* root = NULL;

	do {
		Member x;
		BinNode* temp;

		switch (menu = SelectMenu()) {	//menu의 값에 의해 메뉴가 골라진다.
			//enum을 통해 문자열에 숫자를 할당하면 숫자에 의미를 담을수가 있다...!!
		case ADD:
			//INS_FRONT, 
				//아래의 구문이 굉장히 아름답다
			// sw == MEMBER_NO | MEMBER_NAME, 
			// (MEMBER_NO | MEMBER_NAME) & MEMBER_NO 는 (01 | 10) & 01
			x = ScanMember("삽입", MEMBER_NO | MEMBER_NAME);
			root = Add(root, &x);
			continue;

		case REMOVE:
			//INS_REAR,
			x = ScanMember("삭제", MEMBER_NO);
			Remove(&root, &x);
			continue;

		case SEARCH:
			//RMV_FRONT,
			x = ScanMember("검색", MEMBER_NO);
			if ((temp = Search(root, &x)) != NULL) {
				PrintLnMember(&(temp->data));
			}
			continue;

		case  PRINT:
			//RMV_REAR,
			puts("【모든 노드를 출력】");
			PrintTree(root);
			continue;

		}
	} while (menu != TERMINATE);	// menu != 0이면 계속 실행
	FreeTree(root);

	return 0;
}
