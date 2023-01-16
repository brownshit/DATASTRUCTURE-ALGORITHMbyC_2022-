#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<string.h>
//#include<time.h>

#include"IntQueue.h"


#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}	

int Initialize(IntQue* s, int max) {
	s->num = s->front = s->rear = 0;
	if ((s->que = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}
int Enque(IntQue* s, int x) {
	if (s->num >= s->max)
		return -1;
	else {
		s->num++;
		s->que[s->rear++] = x;		//num에 input하면 안되는이유... 그냥 단순히 개수만 의미하고, 인덱스는 front 와 rear로 disp
		if (s->rear == s->max)
			s->rear = 0;	//굉장히 brillient
		return 0;
	}
}
int Deque(IntQue* s, int* x) {
	if (s->num <= 0)
		return -1;
	else {
		s->num--;
		*x = s->que[s->front++];		//front 값이 하나빠지고 index가 증가!!(전체 num 감소)
				//나중에 front + 1
		if (s->front == s->max)
			s->front = 0;
		return 0;
	}
}
int Peek(const IntQue* s, int* x) {
	if (s->num <= 0)
		return -1;
	*x = s->que[s->front];
	return 0;
}
void Clear(IntQue* s) {
	s->num = s->rear = s->front = 0;
	//이렇게만 해도 다 삭제되는거??
}
int Capacity(const IntQue* s) {
	return s->max;
}
int Size(const IntQue* s) {
	return s->num;
}
int isEmpty(const IntQue* s) {
	return s->num <= 0;		//해당값이 참이면, 큐가 비어있으면 1,아니면 0 반환
}
int isFull(const IntQue* s) {
	return s->num >= s->max;
}
int Search(const IntQue* s, int x) {		//찾으려는 data x
	for (int i = 0; i < s->num; i++) {
		int idx;
		if (s->que[idx = (i + s->front) % s->max] == x) {	//idx에 값을 할당함과 동시에 que[idx] 검사
			return idx;		//x의 index
		}
	}
	return -1;		//searching fail
}
void Print(const IntQue* s) {
	for (int i = 0; i < s->num; i++) {
		printf("%d ", s->que[(i + s->front) % s->max]);
	}
	putchar('\n');
}
void Terminate(IntQue* s) {
	if(s->que != NULL)
		free(s->que);
	s->max = s->num = s->rear = s->front = 0;
}
int main() {
	IntQue que;
	if (Initialize(&que, 64) == -1) {// 64 is max value of que
		puts("queue memory generate was failed...\n");
		return 1;
	}
	while (1) {
		int m, x;
		printf("now data num is ... %d / %d\n", Size(&que), Capacity(&que));
		printf("input menu val...(1)Enque (2)Deque (3)Peek (4)Print (5)end : "); scanf_s("%d", &m);
		
		if (m >= 6 || m <= 0) continue;
		switch (m){
		case 1:	//Enque
			printf("data input : "); scanf_s("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\aError : data Enque failed...");
			continue;
		case 2:	//Deque
			if (Deque(&que, &x) == -1)		//x의 주소를 넘겨서 디큐의 결과인 배출하는 값을 받아온다.
				puts("\aError : data Deque failed...");
			else
				printf("Deque data : %d\n", x);
			continue;
		case 3:	//Peek
			if (Peek(&que, &x) == -1) 
				puts("\aError : data Peek failed...");
			else
				printf("Peek data : %d\n", x);
			continue;
		case 4:
			Print(&que);
			continue;
		case 5:
			Terminate(&que);
			return 0;
		}
	}
	return 0;
}
