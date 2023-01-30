#ifndef ___CircDbLinkedList
#define ___CircDbLinkedList

#include "Member.h"

/*
	#define Null -1		//빈커서
	typedef int Index;		//커서의 자료형		Index라는 별명으로 특수화
*/

/*node*/
typedef struct __node {
	Member			data;	//데이터
	struct __node*	prev;	//앞노드의 포인터
	struct __node*	next;	//다음노드의 포인터
}Dnode;

/*CircDblinked list*/
typedef struct {
	Dnode* head;		//머리 더미노드의 포인터
	Dnode* crnt;		//선택한 노드 포인터
}Dlist;

/*

static Node* AllocNode(void);
static void SetNode(Node* n, const Member* x, const Node* next);

static은 헤더파일에서 선언안해줘도 된다. static예약어 자체가 해당 소스파일에서만 사용하겠다는 의미.
*/

/*연결리스트 초기화*/
void Initialize(Dlist* list);

/*선택한 노드의 데이터를 출력*/
void PrintCurrent(const Dlist* list);

/*선택한 노드의 데이터를 출력(줄바굼 문자 포함)*/
void PrintLnCurrent(const Dlist* list);

/*함수 compare로 x와 같은 노드를 검색*/
Dnode* Search(Dlist* list, const Member* x, int compare(const Member* x, const Member* y));

/*all Printf*/
void Print(const Dlist* list);

/*리스트 역순 출력*/
void PrintReverse(const Dlist* list);

/*선택한 노드의 다음으로 진행*/
int Next(Dlist* list);

/*선택한 노드의 앞으로 진행*/
int Prev(Dlist* list);

/*p가 가리키는 노드 바로뒤에 노드를 삽입*/
void InsertAfter(Dlist* list,Dnode *p, const Member* x);

/*머리에 노드 삽입*/
void InsertFront(Dlist* list, const Member* x);

/*꼬리에 노드 삽입*/
void InsertRear(Dlist* list, const Member* x);

/*p가 가리키는 노드 삭제*/
void Remove(Dlist* list, Dnode* p);

/*머리 노드 삭세 */
void RemoveFront(Dlist* list);

/*꼬리 노드 삭세 */
void RemoveRear(Dlist* list);

/*선택한 노드 삭제*/
void RemoveCurrent(Dlist* list);

/*모드 노드 삭제*/
void Clear(Dlist* list);

/*linked list terminate*/
void Terminate(Dlist* list);

#endif
