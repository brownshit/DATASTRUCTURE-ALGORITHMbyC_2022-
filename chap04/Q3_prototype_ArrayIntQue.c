#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<string.h>
//#include<time.h>

//#include"IntStack.h"


#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}	


/*this is no use of its complexity...InQue had O(n) complexity... should move all index to front*/

typedef struct {
	int max;		//queue capacity
	int num;		//현재 data수
	int* que;		//pointer of queue arr
}ArrayIntQue;

int Initialization(ArrayIntQue* s, int max) {
	s->num = 0;
	if ((s->que = calloc(max, sizeof(int))) == NULL) {
		printf("Generate Queue Failed...\n");
		return -1;
	}
	s->max = max;
	return 0;
}

int enque(ArrayIntQue* s, int x) {
	if (s->num >= s->max) 
		return -1;
	s->que[s->num++] = x;	//값 복사
	return 0;
}
int deque(ArrayIntQue* s) {
	if (s->num <= 0)
		return -1;
	//O(n)의 complexity
	for (int i = 1; i < s->num; i++) {
		//inhere, move every index in queue
		s->que[i - 1] = s->que[i];
	}
	s->que[s->num] = 0;		//clear num's index...
	s->num--;				//size reduce...
	return s->que[0];		//return front value...
}
int peek(const ArrayIntQue* s, int* x) {

}
int Clear(ArrayIntQue* s) {

}
int Capacity(const ArrayIntQue* s) {

}
int Size(const ArrayIntQue* s) {

}
int isEmpty(const ArrayIntQue* s) {

}
int isFull(const ArrayIntQue *s) {

}
int Search(const ArrayIntQue* s, int x) {

}
void Print(const ArrayIntQue* s) {

}

void Terminate(ArrayIntQue* s) {
	free(s->que);
}

int main() {
	ArrayIntQue s;
	int menu, x;


	return 0;
}
