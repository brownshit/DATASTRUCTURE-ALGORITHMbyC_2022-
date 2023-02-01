#include<stdio.h>
#include<stdlib.h>
#include"Member.h"
#include"BinTree.h"


//static methods
/*노드 동적할당*/
static BinNode* AllocbinNode() {
	return calloc(1, sizeof(BinNode));	
	//BinNode형 객체 1개를 생성
}

/*노드 멤버값 설정*/
static void SefBinNode(BinNode* n, const Member *x, const BinNode *left, const BinNode* right) {
	n->data = *x;		//데이터
	n->left = left;
	n->right = right;
	//BinNode형 객체의 3개 멤버에 값을 설정하는 함수
}

//header file methods
BinNode* Search(BinNode* p, const Member* x) {
	int cond = 0;

	if (p == NULL)
		return NULL;	//검색 실패
	else if ((cond == MemberNoCmp(x, &(p->data)) == 0))
		return p;		//검색 성공
	else if (cond < 0)
		Search(p->left, x);		//왼쪽 서브트리에서 검색
	else
		Search(p->right, x);	//오른쪽 서브트리에서 검색
	//recursive solving...
}

/*노드 삽입*/
BinNode* Add(BinNode* p, const Member* x) {
	int cond;
	if (p == NULL) {
		p = AllocbinNode();		//생성
		SefBinNode(p, x, NULL, NULL);		//노드가 없다면...?
	}
	else if ((cond = MemberNoCmp(x, &(p->data))) == 0)
		printf("|| CAUTION ||\n%d는 이미 등록되어 있습니다...\n", x->no);
	else if (cond < 0)
		p->left = Add(p->left, x);
	else
		p->right = Add(p->right, x);
	return p;
}

/*노드 삭제*/
//이게 좀 어렵다.
int Remove(BinNode** root, const Member* x) {
	BinNode* next,* temp;
	BinNode** left;

	BinNode** p = root;	//*p가 해당 노드, root는 해당 노드의 부모노드

	while (1) {
		int cond;
		if (*p == NULL) {
			printf("|| CAUTION ||\n는 이미 등록되어 있습니다...\n", x->no);
			return -1;
		}
		else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break;
		else if (cond < 0)
			p = &((*p)->left);	//왼쪽 서브트리에서 검색 
		else
			p = &((*p)->right);	//오른쪽 서브트리에서 검색
	}

	if ((*p)->left == NULL)
		next = (*p)->right;
	else {
		left = &((*p)->left);
		while ((*left)->right != NULL)
			left = &((*left)->right);
		next = *left;
		*left = (*left)->left;
		next->left = (*p)->left;
		next->right = (*p)->right;
	}

	temp = *p;
	*p = next;
	free(temp);

	return 0;
}

/*모든 노드를 출력*/
//중위순회 방식 사용
void PrintTree(const BinNode* p) {
	if (p != NULL) {
		PrintTree(p->left);
		PrintLnMember(&(p->data));
		PrintTree(p->right);
	}
}

/*모든 노드를 삭제*/
//후위 순회 방식 사용
void FreeTree(BinNode* p) {
	if (p != NULL) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}

//https://lgphone.tistory.com/90
//AVLTree, red_blackTree


