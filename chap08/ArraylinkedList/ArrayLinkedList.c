#include<stdio.h>
#include<stdlib.h>
#include"Member.h"
#include"ArrayLinkedList.h"

//static methods
/*삽입할 레코드의 인덱스를 구한 다음 반환*/
static Index GetIndex(List* list) {
	if (list->deleted == Null)
		return ++(list->max);
	else {
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;	
		return rec;
	}
}

/*지정된 레코드를 삭제 리스트에 등록*/
static void DeleteIndex(List* list, Index idx) {
	if (list->deleted == Null) {	//삭제할 레코드가 없는경우
		list->deleted = idx;
		list->n[idx].Dnext = Null;
	}
	else {
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr;
	}
}

/*n이 가리키는 노드의 각 멤버에 값을 설정*/
static void SetNode(Node* n, const Member* x, Index next) {
	n->data = *x;	//데이터
	n->next = next;	//다음커서
}


//header files methods
/*연결리스트 초기화*/
void Initialize(List* list, int size) {
	list->n = calloc(size, sizeof(Node));
	list->head = Null;		//머리노드
	list->crnt = Null;		//선택노드
	list->max = Null;
	list->deleted = Null;
}

/*함수 compare로 x와 같은 노드를 검색*/
Node* Search(List* list, const Member* x, int compare(const Member* x, const Member* y)) {
	Index ptr = list->head;
	while (ptr != Null) {
		if (compare(&(list->n[ptr].data), x) == 0) {
			list->crnt = ptr;
			return ptr;
		}
		ptr = list->n[ptr].next;		//커서 넘기기
	}
	return Null;		//검색실패
}

/*머리에 노드 삽입*/
void InsertFront(List* list, const Member* x) {
	Index ptr = list->head;
	list->head = list->crnt = GetIndex(list);
	SetNode(&list->n[list->head], x, ptr);
}

/*꼬리에 노드 삽입*/
void InsertRear(List* list, const Member* x) {
	if (list->head == Null)
		InsertFront(list, x);
	else {
		Index ptr = list->head;
		while (list->n[ptr].next != Null)
			ptr = list->n[ptr].next;
		
		list->n[ptr].next = list->crnt = GetIndex(list);
		SetNode(&(list->n[ptr].next), x, Null);		
		//Null is cursor which got value -1...
	}
}

/*머리 노드 삭제 */
void RemoveFront(List* list) {
	if (list->head != Null) {
		Index ptr = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->crnt = ptr;
	}
}

/*꼬리 노드 삭제 */
void RemoveRear(List* list) {
	if (list->head != Null) {
		if (list->n[list->head].next == Null)//head 다음노드가 빔.
			RemoveFront(list);				//결국 1개노드만 있는 경우
		else {
			Index ptr = list->head;
			Index pre;
			while (list->n[ptr].next != Null) {
				pre = ptr;		//pre is pre node of ptr
				ptr = list->n[ptr].next;//move to next node
			}
			//pre와 ptr분리
			list->n[pre].next = Null;
			DeleteIndex(list, ptr);
			list->crnt = pre;	//얘가 이제 새로운 꼬리노드
		}
	}
}

/*선택한 노드 삭제*/
void RemoveCurrent(List* list) {
	if (list->head != Null) {
		if (list->crnt == list->head)//머리노드가 선택되어 있는 경우
			RemoveFront(list);				
		else {
			Index ptr = list->head;
			while (list->n[ptr].next != list->crnt)
				ptr = list->n[ptr].next;//뒤의 조건이 같으면 종료.

			list->n[ptr].next = list->n[list->crnt].next;
			DeleteIndex(list, list->crnt);
			list->crnt = ptr;		//Index자료형은 int(커서를 의미)
		}
	}
}

/*모드 노드 삭제*/
void Clear(List* list) {
	while (list->head != Null)
		RemoveFront(list);
	list->crnt = Null;
}

/*선택한 노드의 데이터를 출력*/
void PrintCurrent(const List* list) {
	if (list->crnt == Null)
		printf("선택노드가 없습니다...");
	else
		PrintMember(&(list->n[list->crnt].data));//data is Member type
}

/*선택한 노드의 데이터를 출력(줄바굼 문자 포함)*/
void PrintLnCurrent(const List* list) {
	PrintCurrent(list);
	putchar('\n');
}

/*all Printf*/
void Print(const List* list) {
	if (list->head == Null) {
		puts("노드가 없습니다...");
	}
	else {
		Index ptr = list->head;
		puts("◁ 모두 보기 ▷");
		while (ptr != Null) {
			PrintLnMember(&(list->n[ptr].data));
			ptr = list->n[ptr].next;	//다음노드
		}
	}
}

/*linked list terminate*/
void Terminate(List* list) {
	Clear(list);
	free(list->n);
}
