#include<stdio.h>
#include<stdlib.h>
#include"Member.h"
#include"ChainHash.h"


//static methods
//use only in ChainHash.c

/*해시 함수(key의 hash값을 반환...)*/
static int Hash(int key, int size) {
	return key % size;
	//나눌 값 size...
}

static void SetNode(Node* n, const Member* x, const Node* next) {
	n->data = *x;		//데이터
	n->next = next;		//다음 노드에 대한 포인터

	//굳이 값 복사에 포인터를 사용하는 이유,,,??
	/*
		구조체에서 매개변수를 주고받을때는 값이 아닌
		포인터로 하는것이 정석이다.
	*/
}


//header file methods

/*해시테이블 초기화*/
int Initialize(ChainHash* h, int size) {
	if ((h->table = calloc(size, sizeof(Node*))) == NULL) {
		//동적 할당 메모리 생성에 실패하면...
		h->size = 0;
		return 0;
	}
	h->size = size;
	for (int i = 0; i < size; i++)
		h->table[i] = NULL;		//빈 더미노드 생성(linkedlist를 위해서...)
	return 1;		//성공적 함수 return...
}

/*검색*/
Node* Search(const ChainHash* h, const Member* x) {
	int key = Hash(x->no, h->size);	//검색하는 데이터의 해시값 찾기...!
	Node* p = h->table[key];		//현재 선택한 노드

	while (p != NULL) {
		if (p->data.no == x->no)	//검색성공
			return p;
		p = p->next;
	}
	return NULL;
}

/*데이터 추가*/
int Add(ChainHash* h, const Member* x) {
	int key = Hash(x->no, h->size);
	Node* p = h->table[key];		//현재 선택한 배열에서의 노드
	Node* temp;

	while (p != NULL) {
		if (p->data.no == x->no) {	//이 키는 이미 등록된 상태...
			//1 won이 있는 상태에서 1 lee등록하면 실패하는 경우.
			return 1;		//추가 실패
		}
		p = p->next;
	}	//같은 키값이 있는지에 대해 검색

	if ((temp = calloc(1, sizeof(Node))) == NULL)
		return 2;		//동적할당 실패

	//리스트의 맨 앞 위치에 노드를 삽입
	
	SetNode(temp, x, h->table[key]);//추가하는 노드에 값을 설정...
	h->table[key] = temp;
	return 0;		//성공적 종료(with add element in hashtable)
}

/*데이터 삭제*/
int Remove(ChainHash* h, const Member* x) {
	int key = Hash(x->no, h->size);
	Node* p = h->table[key];		//현재 선택한 노드
	Node** pp = &(h->table[key]);	//현재 선택한 노드에 대한 포인터

	while (p != NULL) {
		if (p->data.no == x->no) {
			*pp = p->next;		//그 다음 요소를 위로 올려준다.
			free(p);		//해제
			return 0;
		}
		//다음 노드 선택
		pp = &(p->next);
		p = p->next;
	}

	//p == NULL이 되면
	return 1;		//삭제 실패..(data is not exist)
}

/*해시 테이블 덤프(dump)*/
void Dump(const ChainHash* h) {

	//해시 테이블을 통째로 출력(dump)하는 내용 
	for (int i = 0; i < h->size; i++) {
		Node* p = h->table[i];
		printf("%02d", i);
		while (p != NULL) {
			printf("→ %d (%s)	", p->data.no, p->data.name);
			p = p->next;
		}
		putchar('\n');
	}
}

/*모든 데이터 삭제*/
void Clear(ChainHash* h) {
	for (int i = 0; i < h->size; i++) {
		Node* p = h->table[i];	//현재 선택한 노드
		while (p != NULL) {
			Node* next = p->next;
			free(p);
			p = next;
		}
		h->table[i] = NULL;		//p == NULL이 되면 아예 삭제해버린다.
				//모든 버킷을 공백으로 만든다.
	}
}

/*해시 테이블 종료*/
void Terminate(ChainHash* h) {
	Clear(h);			//all data clear
	free(h->table);		//해시 테이블 배열의 메모리 해제
	h->size = 0;		//테이블 크기 0으로 초기화...
}
