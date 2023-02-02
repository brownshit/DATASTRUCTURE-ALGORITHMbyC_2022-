#include<stdio.h>
#include<stdlib.h>
#include"Member.h"
#include"ClosedHash.h"


//static methods

//해시함수
static int hash(int key, int size) {
	return key % size;
}

//재해시 함수
static int rehash(int key, int size) {
	return (key + 1) % size;
}

//노드의 각 멤버에 값을 설정
static void SetBucket(Bucket* n, const Member* x, Status stat) {
	n->data = *x;
	n->stat = stat;
}


//header file methods

/*해시테이블 초기화*/
int Initialize(ClosedHash* h, int size) {
	if ((h->table = calloc(size, sizeof(Bucket))) == NULL) {	//생성 실패
		h->size = 0;
		return 0;
	}
	h->size = size;
	for (int i = 0; i < size; i++)
		h->table[i].stat = Empty;		//공백으로 변경.. state
	return 1;
}

/*검색*/
Bucket* Search(const ClosedHash* h, const Member* x) {
	int key = hash(x->no, h->size);		//검색할 데이터의 해시값
	Bucket* p = &(h->table[key]);		//현재 선택한 노드
	for (int i = 0; p->stat != Empty && i < h->size; i++) {		//Empty 만나면 종료
		if (p->stat == Occupied && p->data.no == x->no)
			return p;
		key = rehash(key, h->size);		//재해시
		p = &(h->table[key]);
	}
	return NULL;
}

/*데이터 추가*/
int Add(ClosedHash* h, const Member* x) {
	int key = hash(x->no, h->size);		//검색할 데이터의 해시값
	Bucket* p = &(h->table[key]);		//현재 선택한 노드
	if (Search(h, x))		//if문의 조건은 양수면 모두 참으로 간주...
		return 1;			//검색이 되었으므로 종료한다.
	for (int i = 0; i < h->size; i++) {
		if (p->stat == Empty || p->stat == Deleted) {
			//add data...
			SetBucket(p, x, Occupied);
			return 0;		//성공적..
		}
		//조건문에서의 실패...해당 해시가 차있다면..
		key = rehash(key, h->size);		//재해시
		p = &(h->table[key]);
	}
	return 2;	//해시 테이블이 가득 참...
}

/*데이터 삭제*/
int Remove(ClosedHash* h, const Member* x) {
	Bucket* p = Search(h, x);
	if (p == NULL)
		return 1;		//이 키값은 존재하지 않음...
	p->stat = Deleted;
	return 0;
}

/*해시 테이블 덤프(dump)*/
void Dump(const ClosedHash* h) {
	for (int i = 0; i < h->size; i++) {
		printf("%02d : ", i);
		switch (h->table[i].stat) {
		case Occupied:
			printf("%d(%s)\n", h->table[i].data.no, h->table[i].data.name);
			continue;
		case Empty:
			printf("--미 등록--\n");
			continue;
		case Deleted:
			printf("--삭제 완료--\n");
			continue;
		}
	}
}

/*모든 데이터 삭제*/
void Clear(ClosedHash* h) {
	for (int i = 0; i < h->size; i++)
		h->table[i].stat = Empty;
}

/*해시 테이블 종료*/
void Terminate(ClosedHash* h) {
	Clear(h);
	free(h->table);
	h->size = 0;
}
