//#pragma once		is same as
#ifndef ___IntQueue
#define ___IntQueue
//by ring buffer to make queue

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int* que;
}IntQue;

int Initialize(IntQue* s, int max);
int Enque(IntQue* s, int x);
int Deque(IntQue* s, int* x);
int Peek(const IntQue* s, int* x);
void Clear(IntQue* s);
int Capacity(const IntQue* s);
int Size(const IntQue* s);
int isEmpty(const IntQue* s);
int isFull(const IntQue* s);
int Search(const IntQue* s, int x);
void Print(const IntQue* s);
void Terminate(IntQue* s);

#endif
