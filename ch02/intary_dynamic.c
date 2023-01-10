#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

int main()
{	
	int na;		//배열 a의 요소 개수
	printf("요소개수 : ");
	scanf_s("%d", &na);
	int* a = calloc(na, sizeof(int));		//na 사이즈 만큼의 동적 메모리 (heap에)할당.
	if (a == NULL) { puts("메모리 확보 실패."); }
	else {
		printf("%d 개의 int input...\n", na);
		for (int i = 0; i < na; i++) {
			printf("a[%d] = ", i);
			scanf_s("%d", &a[i]);
		}
		printf("각 요솟값을 다음과 같다...\n");
		for (int i = 0; i < na; i++) 
			printf("a[%d] = %d\n", i,a[i]);

		free(a);
	}


	return 0;
}

/*
	
*/
