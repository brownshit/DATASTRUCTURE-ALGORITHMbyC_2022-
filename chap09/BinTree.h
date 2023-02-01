#ifndef ___BinTree
#define ___BinTree

#include "Member.h"

/*
	#define Null -1		//빈커서
	typedef int Index;		//커서의 자료형		Index라는 별명으로 특수화
*/

/*node*/
typedef struct __bnode {
	Member data;		//데이터
	struct __bnode* left;		//왼쪽 노드에 대한 데이터
	struct __bnode* right;		//오른쪽 노드에 대한 데이터

}BinNode;
/*

static Node* AllocNode(void);
static void SetNode(Node* n, const Member* x, const Node* next);

static은 헤더파일에서 선언안해줘도 된다. static예약어 자체가 해당 소스파일에서만 사용하겠다는 의미.
*/

/*검색*/
BinNode* Search(BinNode* p, const Member* x);

/*노드 삽입*/
BinNode* Add(BinNode* p, const Member* x);

/*노드 삭제*/
int Remove(BinNode** root, const Member* x);

/*모든 노드를 출력*/
void PrintTree(const BinNode* p);

/*모든 노드를 삭제*/
void FreeTree(BinNode* p);


#endif
