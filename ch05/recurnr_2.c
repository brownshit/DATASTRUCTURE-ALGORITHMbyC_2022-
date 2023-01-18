#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<string.h>
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}	

/*		구조체
typedef struct {
	int max;	//스택의 최대용량
	int ptr;	//스택포인터 _스택의 요소개수
	int* stk;	//스택으로 사용할 배열 지칭 포인터
}IntStack;
*/
typedef struct {
	int max;	//스택의 최대용량
	int ptr;	//스택포인터 _스택의 요소개수
	int* stk;	//스택으로 사용할 배열 지칭 포인터
}IntStack;

//인터페이스의 구현같이...!!

int Initialize(IntStack* s, int max) {
	s->ptr = 0;		//(*s).ptr = 0; 과 같다.
	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;	//배열 생성의 실패
		printf("stack building was failed...");
		return -1;
	}
	//동적할당 배열 생성의 성공
	s->max = max;
	return 0;
}

//push do not operate well
int Push(IntStack* s, int x) {
	if (s->ptr >= s->max)
		return -1;		//가득 차 있으면 -1을 반환한다.
	s->stk[s->ptr++] = x;		// stk[ptr] 에 x대입, ptr 증가	
	return 0;
	//line remove shift + delete
}
int Pop(IntStack* s, int* x) {
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[--s->ptr];		//연산자 우선순위가 ->가 1등이다.
								//즉, s->ptr이 줄고나서 그다음 연산이 실행된다.
	return 0;
}
int Peek(const IntStack* s, int* x) {
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];		//x의 요소를 변경시켜서 main에서 불러오는 방식을 사용?
	return 0;
}
void Clear(IntStack* s) {
	s->ptr = 0;
}
int Capacity(const IntStack* s) {
	return s->max;
}
int Size(const IntStack* s) {
	return s->ptr;
}
int IsEmpty(const IntStack* s) {
	return s->ptr <= 0;	//if it is empty, 1 return
}
int IsFull(const IntStack* s) {
	return s->ptr >= s->max;	//if ptr >= max, return 1
}
int Search(const IntStack* s, int x) {
	//linear search bottom to top.
	for (int i = s->ptr - 1; i >= 0; i--) {
		if (s->stk[i] == x)		//stk is pointer, and should focus on its use !
			return i;		//index return 
	}
	return -1;	//searching failed...
}
void Print(const IntStack* s) {
	//all data printing
	int i;
	for (int i = 0; i < s->ptr; i++) {
		printf("%d ", s->stk[i]);
	}
	putchar('\n');
	//puts는 문자열 전용 출력함수.
}
void Terminate(IntStack* s) {
	//종료
	if (s->stk != NULL) {
		free(s->stk);
	}
	s->max = s->ptr = 0;	//이게 된다!!
}


void recur(int n) {
	IntStack stk;
	Initialize(&stk, 100);
Top:
	//this area deal n-1 part..!
	if (n > 0) {
		//LIFO
		Push(&stk, n);		//n push
		n -= 1;
		goto Top;
	}
	if (!IsEmpty(&stk)) {		//if stack is not empty,
		Pop(&stk, &n);
		printf("%d\n", n);
		n -= 2;
		goto Top;
	}
	Terminate(&stk);
}

int main() {
	int n; printf("input number : "); scanf_s("%d", &n); printf("this is result of simuler recursive(using Stack...)\n"); recur(n);
	return 0;
}
