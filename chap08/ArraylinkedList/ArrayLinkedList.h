#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList

#include "Member.h"

#define Null -1		//빈커서
typedef int Index;		//커서의 자료형		Index라는 별명으로 특수화

/*node*/
typedef struct __node {
	Member	data;	//데이터
	Index	next;	//다음 요소의 포인터
	Index	Dnext;	//프리 리스트 다음 노드
}Node;

/*linked list*/
typedef struct {
	Node* n;		//리스트 본체
	
	Index head;	//머리 노드
	Index max;	//사용중인 꼬리 레코드
	Index deleted;		//프리 리스트의 머리커서
	Index crnt;	//선택 노드
}List;
/*

static Node* AllocNode(void);
static void SetNode(Node* n, const Member* x, const Node* next);

static은 헤더파일에서 선언안해줘도 된다. static예약어 자체가 해당 소스파일에서만 사용하겠다는 의미.

*/

/*연결리스트 초기화*/
void Initialize(List* list, int size);

/*함수 compare로 x와 같은 노드를 검색*/
Node* Search(List* list, const Member* x, int compare(const Member* x, const Member* y));

/*머리에 노드 삽입*/
void InsertFront(List* list, const Member* x);

/*꼬리에 노드 삽입*/
void InsertRear(List* list, const Member* x);

/*머리 노드 삭세 */
void RemoveFront(List* list);

/*머리 노드 삭세 */
void RemoveRear(List* list);

/*선택한 노드 삭제*/
void RemoveCurrent(List* list);

/*모드 노드 삭제*/
void Clear(List* list);

/*선택한 노드의 데이터를 출력*/
void PrintCurrent(const List* list);

/*선택한 노드의 데이터를 출력(줄바굼 문자 포함)*/
void PrintLnCurrent(const List* list);

/*all Printf*/
void Print(const List* list);

/*linked list terminate*/
void Terminate(List* list);

#endif
