
#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

#include"IntStack.h"

//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
#define swap(type, x, y)do{type t = x; x = y; y = t; }while(0)      //run just 1 time

void print_quick_state(int a[], int left, int right) {
    printf("a[%d] ~ a[%d] : {", left, right);
    for (int i = left; i < right; i++)
        printf("%d ", a[i]);
    printf("%d }\n", a[right]);
}

/*--not recursive Quick sorting--*/
//by using stack
void quick(int a[], int left, int right) {
    IntStack lstack;      //나눌 첫요소 인덱스의 스택
    IntStack rstack;      //나눌 끝요소 인덱스의 스택

    Initialize(&lstack, right - left + 1);
    Initialize(&rstack, right - left + 1);

    Push(&lstack, left);   //set index of left
    Push(&rstack, right);   //set index of left

    while (!IsEmpty(&lstack)) {//비어있지 않으면 실행한다.

        int pl = (Pop(&lstack, &left), left);   //???
        /*      The GOAT 김기용 교수님의 답변...
        [김기용] [오후 8:22] 
        Pop(&lstack, %left);
        int pl = left;
        이랑 같은 코드임... 쫄거 없다! 왠만하면 이런 형식의 코드는 지양 하는것이 좋다
        */
        //팝한 값을 left에 대입하고 다시 pl 에 대입한다.
        int pr = (Pop(&rstack, &right), right);

        //pivot
        int pivot = a[(left + right) / 2];

        do {        //main algo of qsort...!
            while (a[pl] < pivot) pl++;
            while (a[pr] > pivot)pr--;
            if (pl <= pr) {
                swap(int, a[pl], a[pr]);
                pl++; pr--;
            }
        } while (pl<=pr);

        if (left < pr) {
            Push(&lstack, left);
            Push(&rstack, pr);
        }
        if (pl < right) {
            Push(&lstack, pl);
            Push(&rstack, right);
        }
    }
    Terminate(&lstack);
    Terminate(&rstack);     //kill stack when end the function...
}



/*--recursive Quick sorting--*/
//initial call of quick in main, left = 0 && right = n-1
void quick_recursive(int a[], int left, int right) {
    int pl = left;
    int pr = right;
    int pivot = a[(pl + pr) / 2];   //this is pivot

    //call state
    print_quick_state(a, pl, pr);

    //main alg partition. basic of quick
    do {
        while (a[pl] < pivot) pl++;
        while (a[pr] > pivot) pr--;

        //swap alg
        if (pl <= pr) {//index compare
            swap(int, a[pl], a[pr]);
            pl++;   pr--;
        }
    } while (pl <= pr);   //크게되면 종료.

    //for recursive operation, call quick again...
    if (left < pr)   quick(a, left, pr);//pr 아래에 left가 있는 경우 
    if (right > pl)   quick(a, pl, right);//pr 아래에 left가 있는 경우 
}

//divide a into group
void partition(int a[], int n) {
    int pl = 0;
    int pr = n - 1;
    int pivot = a[n / 2];      //pivot..!
    do {
        while (a[pl] < pivot) pl++;      //pl>=pivot인경우 종료
        while (a[pr] > pivot) pr--;      //pr<=pivot인경우 종료
        //swap condition
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++; pr--;      //      +=1
        }
    } while (pl <= pr);      //pl이 pr보다 크면 반복종료...
    puts("[partition]============================================");
    printf("[pivot] : %d\n", a[pivot]);
    printf("[under pivot group] : ");
    for (int i = 0; i <= pl - 1; i++) {//pl-1 == pivot...!
        printf("%d ", a[i]);
    }
    putchar('\n');
    printf("[[pivot group]] : ");
    for (int i = pr + 1; i <= pl - 1; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
    printf("[over pivot group] : ");
    for (int i = pr + 1; i < n; i++) {//pl-1 == pivot...!
        printf("%d ", a[i]);
    }
    putchar('\n');
    puts("=======================================================");
}

int is_sorted(const int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
}

int main() {
    int nx;
    puts("quick_sorting...");
IDX:
    printf("element num input : "); scanf_s("%d", &nx);

    int* array = calloc(nx, sizeof(int));      //size, data_type

    for (int i = 0; i < nx; i++) {
        printf("element[%d]input : ", i); scanf_s("%d", &array[i]);
    }

    //partition(array, nx);
    quick(array, 0, nx - 1);
    /*

    */
    //정렬 상태 검사...
    if (is_sorted == 0) {
        printf("code is not sorted yet...");
        free(array);
        goto IDX;
    }
    else {
        puts("asending order sorting complete...!!");
    }
    //print array...
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, array[i]);

    free(array);   //free stack memory by dynamic allocation
    return 0;


    return 0;
}


int Initialize(IntStack* s, int max) {
    s->ptr = 0;      //(*s).ptr = 0; 과 같다.
    if ((s->stk = calloc(max, sizeof(int))) == NULL) {
        s->max = 0;   //배열 생성의 실패
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
        return -1;      //가득 차 있으면 -1을 반환한다.
    s->stk[s->ptr++] = x;      // stk[ptr] 에 x대입, ptr 증가   
    return 0;
    //line remove shift + delete
}
int Pop(IntStack* s, int* x) {
    if (s->ptr <= 0)
        return -1;
    *x = s->stk[--s->ptr];      //연산자 우선순위가 ->가 1등이다.
                         //즉, s->ptr이 줄고나서 그다음 연산이 실행된다.
    return 0;
}
int Peek(const IntStack* s, int* x) {
    if (s->ptr <= 0)
        return -1;
    *x = s->stk[s->ptr - 1];      //x의 요소를 변경시켜서 main에서 불러오는 방식을 사용?
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
    return s->ptr <= 0;   //if it is empty, 1 return
}
int IsFull(const IntStack* s) {
    return s->ptr >= s->max;   //if ptr >= max, return 1
}
int Search(const IntStack* s, int x) {
    //linear search bottom to top.
    for (int i = s->ptr - 1; i >= 0; i--) {
        if (s->stk[i] == x)      //stk is pointer, and should focus on its use !
            return i;      //index return 
    }
    return -1;   //searching failed...
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
    s->max = s->ptr = 0;   //이게 된다!!
}
