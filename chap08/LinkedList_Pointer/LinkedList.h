#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

/*node*/
typedef struct __node {
	Member			data;	//데아터
	struct __node* next;	//다음 요소의 포인터
}Node;

/*linked list*/
typedef struct {
	Node* head;		//머리 노드에 대한 포인터
	Node* crnt;		//선택한 노드에 대한 포인터	
}List;

/*연결리스트 초기화*/
void Initialize(List* list);

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
