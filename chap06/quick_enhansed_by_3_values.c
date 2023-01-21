
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

int sort3elem(int x[], int a, int b, int c) {
    //3개의 값을 오름차순 정렬한다.
    if (x[b] < x[a])   swap(int, x[b], x[a]);
    if (x[c] < x[b])   swap(int, x[c], x[b]);
    if (x[b] < x[a])   swap(int, x[b], x[a]);       //굉장히 중요한 정렬...
    return b;       //3재의 중앙값의 인덱스를 반환한다.
}

/*--enhanced recursive Quick sorting--*/
void quick(int a[], int left, int right) {      //p.249 조금더 최적화된 퀵정렬
    int pl = left;
    int pr = right;
    int m = sort3elem(a, pl,(pl+pr)/2, pr);
    int pivot = a[m];   //this is not index but value.

    swap(int, a[m], a[right - 1]);//가운데와 끝에서 2번째 요소의 교환.
    pl++;       
    pr -= 2;    //index shifting...!
    
    do {
        while (a[pl] < pivot) pl++;
        while (a[pr] > pivot) pr--; //작거나 같으면 정지...
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++; pr--;
        }
    } while (pl<=pr);
    if (left < pr) quick(a, left, pr);
    if (pl < right) quick(a, pl, right);        //recursive...

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
    


    //print array...
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, array[i]);

    free(array);   //free stack memory by dynamic allocation
    return 0;


    return 0;
}
