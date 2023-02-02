#ifndef ___ClosedHash
#define ___ClosedHash

#include "Member.h"

/*요소의 상태*/
typedef enum {	//노드를 3개의 상태를 가질수 있다.
	Occupied, Empty, Deleted
}Status;
//위와같이 초기화가 안된enum자료형은 맨 첫 요소부터 자동으로 0,1,2가 할당된다.

/*버킷을 나타내는 노드*/
typedef struct __node {
	Member			data;		//데이터
	Status			stat;		//요소의 상태
}Bucket;		//이걸로 linked_list 만든다

/*해시테이블*/
typedef struct {
	int		size;	//해시 테이블 크기
	Bucket*	table;	//해시테이블의 첫 요소에 대한 포인터
}ClosedHash;

/*해시테이블 초기화*/
int Initialize(ClosedHash* h, int size);

/*검색*/
Bucket* Search(const ClosedHash* h, const Member* x);

/*데이터 추가*/
int Add(ClosedHash* h, const Member* x);

/*데이터 삭제*/
int Remove(ClosedHash* h, const Member* x);

/*해시 테이블 덤프(dump)*/
void Dump(const ClosedHash* h);

/*모든 데이터 삭제*/
void Clear(ClosedHash* h);

/*해시 테이블 종료*/
void Terminate(ClosedHash* h);

#endif
