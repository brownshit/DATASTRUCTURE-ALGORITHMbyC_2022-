#ifndef ___IntStack

#define ___IntStack

/*--스택의 구현--*/
typedef struct {
	int max;	//스택의 최대용량
	int ptr;	//스택포인터 _스택의 요소개수
	int* stk;	//스택으로 사용할 배열 지칭 포인터
}IntStack;

//스택초기화
int Initialize(IntStack* s, int max);

//datainput
int Push(IntStack* s, int x);

//upper data remove and print it
int Pop(IntStack* s, int x);

//맨위의 데이터 반환
int Peek(const IntStack* s, int n);

//모두 삭제
void Clear(IntStack *s);

//stack 용량
int Capacity(const IntStack* s);

//전체 data 개수
int Size(const IntStack* s);

//스택 비어있는지 검사
int IsEmpty(const IntStack* s);

//스택이 모두 찼는지 검사
int IsFull(const IntStack* s);

//스택에서 검사
int Search(const IntStack* s);

//모든 데이터 출력
void Print(const IntStack* s);

//스택 종료
void Terminate(IntStack* s);


#endif
