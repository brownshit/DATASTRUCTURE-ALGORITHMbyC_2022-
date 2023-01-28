#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

#include "Member.h"
#include "LinkedList.h"

/*dynamic node generate*/
static Node* AllocNode(void) {
	return calloc(1, sizeof(Node));
}

/*n이 가리키는 노드의 각 멤버에 값을 설정*/
static void SetNode(Node* n, const Member* x, const Node* next) {
	n->data = *x;		//데이터
	n->next = next;
}

void Initialize(List* list) {	//make empty linked list
	list->head = NULL;	//머리노드
	list->crnt = NULL;	//선택노드
	/*
	연결리스트가 비어있는지 확인하는 법
	0개 요소...
	list->head == NULL
	1개 요소...
	list->head->next == NULL
	2개 요소...
	list->head->next->next = NULL
		얘의 데이터...
		list->head->next->data
	.
	.
	.
	*/
}


//아래의 인자로 나오는 함수 
//	int compare(const Member* x, const Member* y) 는 함수 포인터로 들어간다.
//	main함수에서 MemberNoCmp이 이 자리에 들어가게 된다. 
//	함수 이름은 중요하지 않고, 인자로 들어가는 함수가 
//	compare함수의 역할을 하게된다.

Node* Search(List* list, const Member* x, int compare(const Member* x, const Member* y)) {
	Node* ptr = list->head;
	while (ptr != NULL) {	//ptr이 head포인터로 초기화 되어있는 상태이다.
		if (compare(&(ptr->data), x) == 0) {
			//키 값이 같은경우...
			list->crnt = ptr;	//현재 위치에 ptr저장
			return ptr;
		}
		ptr = ptr->next;		//키 값이 같지 않다면 next...
	}
	return NULL;	//검색 실패
}

//compare 함수는,,,?

void InsertFront(List* list, const Member* x) {
	//ptr intialization
	Node* ptr = list->head;		//using same memory
	list->head = list->crnt = AllocNode();		//책 그림 보기...p.333
	SetNode(list->head, x, ptr);	//node,member,node
}

void InsertRear(List* list, const Member* x) {
	if (list->head == NULL)
		InsertFront(list, x);//머리에 삽입... 노드가 없으면 둘이 같다.
	else {
		Node* ptr = list->head;
		while (ptr->next != NULL)
			ptr = ptr->next;//이게 ptr->next가 없을때까지 계속 반복,,,

		ptr->next = list->crnt = AllocNode();

		SetNode(ptr->next, x, NULL);
		//다음노드에 NULL을 넣어 꼬리노드가 어떤노드도 가리키지 않게 한다.
	}
}

void RemoveFront(List* list) {
	if (list->head != NULL) {
		Node* ptr = list->head->next;	//헤드의 다음 요소를 가리킨다.
		free(list->head);		//현재 머리노드 메모리 할당 해제
		list->head = list->crnt = ptr;		//새로운 머리노드
	}
}

//꼬리노드 삭제함수
void RemoveRear(List* list) {
	if (list->head != NULL) {
		if ((list->head)->next == NULL) {//노드가 1개인경우...
			RemoveFront(list);
		}
		else {
			Node* ptr = list->head;
			Node* pre = 0;
			//원래 nullptr사용해야하는게 맞긴 한데 그거 c11부터 사용이 가능

			//while 문 종료되면 ptr은 꼬리, pre는 꼬리에서 두번째 요소 카리킨다.
			while (ptr->next != NULL) {
				pre = ptr;
				ptr = ptr->next;
				//pre는 항상 ptr보다 하나 앞의 노드를 가리키게 된다.
			}
			pre->next = NULL;	//ptr과 pre관계를 disconnect
			free(ptr);
			list->crnt = pre;
		}
	}
}

//crnt위치의 노드를 제거...
void RemoveCurrent(List* list) {
	if (list->head != NULL) {
		if (list->crnt == list->head) {//머리 노드가 선택되어있는 상황이라면,,,
			RemoveFront(list);
		}
		else {
			Node* ptr = list->head;
			while (ptr->next != list->crnt) //ptr이 crnt에 도달할때까지 반복
				ptr = ptr->next;

			//ptr은 선택한 노드의 바로 앞 노드를 가리킨다.
			ptr->next = list->crnt->next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

//all Clear
void Clear(List* list) {
	while (list->head != NULL)//텅 빌때까지 
		RemoveFront(list);		//머리노드를 삭제
	list->crnt = NULL;
}

//선택한 노드의 데이터를 출력
void PrintCurrent(const List* list) {
	if (list->crnt == NULL) {
		printf("선택한 노드가 없습니다.");
	}
	else
		PrintMember(&list->crnt->data);
}

void PrintLnCurrent(const List* list) {
	PrintCurrent(list);
	putchar('\n');
}

//리스트의 모든 노드 출력...
void Print(const List* list) {
	if (list->head == NULL)
		puts("노드가 없습니다.");
	else {
		Node* ptr = list->head;
		puts("◁ 모두 보기 ▷");
		while (ptr != NULL) {
			PrintLnMember(&(ptr->data));		//호출시에 주소로 호출!
			ptr = ptr->next;
		}
	}
}

//연결리스트 종료
void Terminate(List* list) {
	Clear(list);
}
