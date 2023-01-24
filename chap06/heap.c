
#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>
#define swap(type, x,y)do{type t = x; x = y; y = t;}while(0)

/*a[left] ~ a[right]를 힙으로 만드는 함수*/
static void downheap(int a[], int left, int right) {		//one step
	int temp = a[left];
	int parent;
	int child;
	for (parent = left; parent < (right + 1)/2; parent = child) {
		int cl = parent * 2 + 1;	//왼쪽 자식
		int cr = cl + 1;			//오른쪽 자식
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;		//right는 맨 마지막 배열인자
			//만약 cr이 right 보다 크면 cl하나밖에 없는것...자식에 cl,
			//이경우가 아니면 자식이 둘, 큰 값이 child에 들어가게 된다.
		if (temp >= a[child])
			break;
		a[parent] = a[child];
	}
	a[parent] = temp;
}

void heapsort(int a[], int n) {
	for (int i = (n - 1) / 2; i >= 0; i--)
		downheap(a, i, n - 1);		//left 는 부모의 인덱스, right는 마지막 요소...		//힙 만들기
	for (int i = 0; i < n; i++)
		printf("heap [%d] : %d\n", i, a[i]);
	for (int i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]);		//배열 마지막 요소와 루트를 바꾸고,
		downheap(a, 0, i - 1);		//루트는 i번째에 fix, 나머지 요소에 대한 힙정렬을 진행한다.
	}
}

int main() {
	int nx;
	puts("힙 정렬");
	printf("요소 개수 : "); scanf_s("%d", &nx);
	int* x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i); scanf_s("%d", &x[i]);
	}
	heapsort(x, nx);
	puts("오름 차순 정렬 완료,,,");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);
	return 0;
}
