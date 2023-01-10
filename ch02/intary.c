#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#define N 5
int main()
{	
	int a[N];
	for (int i = 0; i < N; i++) {
		printf("a[%d] : ", i); scanf_s("%d", &a[i], sizeof(a[i]));		//at scanf, a[i]는 요소,즉, 주소연산자 &가 붙는게 맞음.
		//, sizeof(a[i]) 이부분을 3번째 인수로 넣는게 맞을까?
			//넣든 안넣든 무관한거같은데 string 처리시에는 있는게 맞음.
	}
	puts("각 요소의 값...");
	for (int i = 0; i < N; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}

/*
	
*/
