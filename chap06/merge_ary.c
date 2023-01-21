#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

//정렬을 마친 두 배열을 하나의 배열로 정렬에서 넣기.
void merge(const int a[], int na, const int b[], int nb, int c[]) {
	int pa = 0; int pb = 0; int pc = 0;	//배열의 커서
	while (pa < na && pb < nb)
		c[pc++] = ((a[pa] <= b[pb]) ? a[pa++] : b[pb++]);
	while (pa < na)
		c[pc++] = a[pa++];
	while (pb < nb)
		c[pc++] = b[pb++];
}

int main() {
	int na, nb;
	printf("a의 요소 개수 : "); scanf_s("%d", &na);
	printf("b의 요소 개수 : "); scanf_s("%d", &nb);

	int* a = calloc(na, sizeof(int));
	int* b = calloc(na, sizeof(int));
	int* c = calloc(na+nb, sizeof(int));

	printf("a[0] : "); scanf_s("%d", &a[0]);
	for (int i = 1; i < na; i++) {
		do {
			printf("a[%d] : ", i);
			scanf_s("%d", &a[i]);
		} while (a[i]< a[i-1]);
	}

	printf("b[0] : "); scanf_s("%d", &b[0]);
	for (int i = 1; i < nb; i++) {
		do {
			printf("b[%d] : ", i);
			scanf_s("%d", &b[i]);
		} while (b[i] < b[i - 1]);
	}
	
	merge(a, na, b, nb, c);
	puts("배열 a와 b를 병합하여 배열 c에 저장하였습니다.");
	for (int i = 0; i < na + nb; i++) {
		printf("c[%2d] = %2d\n", i, c[i]);
	}

	free(c); free(b); free(a);
	return 0;
}
