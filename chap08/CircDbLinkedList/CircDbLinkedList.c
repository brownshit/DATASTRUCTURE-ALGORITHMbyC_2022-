#include<stdio.h>
#include<stdlib.h>
#include"Member.h"
#include"CircDbLinkedList.h"

//static methods
static Dnode* AllocDnode() {
	return calloc(1, sizeof(Dnode));
}

/*노드의 각 멤버값을 설정*/
static void SetDnode(Dnode* n, const Member* x, const Dnode* prev, const Dnode* next) {
	n->data = *x;	//데이터
	n->prev = prev;
	n->next = next;
}

/*list empty state*/
static int IsEmpty(const Dlist* list) {
	return list->head->next == list->head;	//원형 이중연결리스트이기 때문에...
}

//header files methods
/*연결리스트 초기화*/
void Initialize(Dlist* list) {
	Dnode* dummynode = AllocDnode();	//dummy node generate...
	list->head = list->crnt = dummynode;
	dummynode->prev = dummynode->next = dummynode;		//there is only one dummy node...!
	/*	what dummy node do?
	* :	
	*/
}

/*선택한 노드의 데이터를 출력*/
void PrintCurrent(const Dlist* list) {
	if (IsEmpty(list))
		printf("선택한 노드가 없습니다.\n");
	else
		PrintMember(&(list->crnt->data));
}

/*선택한 노드의 데이터를 출력(줄바굼 문자 포함)*/
void PrintLnCurrent(const Dlist* list) {
	PrintCurrent(list);
	putchar('\n');
}

/*함수 compare로 x와 같은 노드를 검색*/
Dnode* Search(Dlist* list, const Member* x, int compare(const Member* x, const Member* y)) {
	//진짜 머리노드는 더미노드가 아니라 list->head->next가 머리!
	Dnode *ptr = list->head->next;	
	
	while (ptr != list->head) {
		if (compare(&(ptr->data), x) == 0) {
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->next;		//커서 넘기기
	}
	return NULL;		//검색실패
}

/*all Printf*/
void Print(const Dlist* list) {
	if (IsEmpty(list)) {
		puts("노드가 없습니다...");
	}
	else {
		Dnode *ptr = list->head->next;
		puts("◁ 모두 보기 ▷");
		while (ptr != list->head) {
			PrintLnMember(&(ptr->data));
			ptr = ptr->next;	//다음노드
		}
	}
}

/*리스트 역순 출력*/
void PrintReverse(const Dlist* list) {
	if (IsEmpty(list))
		puts("노드가 없습니다...");
	else {
		Dnode* ptr = list->head->next;

		puts("◁ 모두 보기 ▷");
		while (ptr != list->head) {
			PrintLnMember(&(ptr->data));
			ptr = ptr->prev;		//ptr get front node of previous ptr... 
		}
	}
}

/*선택한 노드의 다음으로 진행*/
int Next(Dlist* list) {
	if (IsEmpty(list) || list->crnt->next == list->head)
		return 0;		//if there's dummy node or none, fail to move backward...
	list->crnt = list->crnt->next;
	return 1;		//if it sucess
}

/*선택한 노드의 앞으로 진행*/
int Prev(Dlist* list) {
	if (IsEmpty(list) || list->crnt->next == list->head)
		return 0;		//can not move backward
	list->crnt = list->crnt->prev;
	return 1;
}

/*p가 가리키는 노드 바로뒤에 노드를 삽입*/
void InsertAfter(Dlist* list, Dnode* p, const Member* x) {
	Dnode* ptr = AllocDnode();
	Dnode* nxt = p->next;		//다음 노드의 포인터
	
	p->next = p->next->prev = ptr;
	/*앞 노드의 뒤쪽 포인터 p->next와 뒤 노드의 앞쪽 포인터 p->next->prev가 모두 ptr을 가리키게...*/
	SetDnode(ptr, x, p, nxt);
	list->crnt = ptr;
}

/*머리에 노드 삽입*/
void InsertFront(Dlist* list, const Member* x) {
	InsertAfter(list, list->head, x);
}

/*꼬리에 노드 삽입*/
void InsertRear(Dlist* list, const Member* x) {
	InsertAfter(list, list->head->prev, x);		//list->head->prev 는 꼬리노드이다
}

/*p가 가리키는 노드 삭제*/
void Remove(Dlist* list, Dnode* p) {
	p->prev->next = p->next;
	p->next->prev = p->prev;

	list->crnt = p->prev;		//삭제한 노드의 앞쪽 노드를 선택

	free(p);
	if (list->crnt == list->head)
		list->crnt = list->head->next;
}

/*머리 노드 삭제 */
void RemoveFront(Dlist* list) {
	if (!IsEmpty(list))
		Remove(list, list->head->next);
}

/*꼬리 노드 삭제 */
void RemoveRear(Dlist* list) {
	if (!IsEmpty(list))
		Remove(list, list->head->prev);
}

/*선택한 노드 삭제*/
void RemoveCurrent(Dlist* list) {
	if (list->crnt != list->head)
		Remove(list, list->crnt);
}

/*모드 노드 삭제*/
void Clear(Dlist* list) {
	while (!IsEmpty(list))
		RemoveFront(list);
}

/*linked list terminate*/
void Terminate(Dlist* list) {
	Clear(list);
	free(list->head);
}
