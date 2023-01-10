#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

int maxof(const int a[], int n) {		//const 상수화. 배열의 변형 억제.
	int max = a[0];
	for (int i = 0; i < n; i++) {
		if (max < a[i]) { max = a[i]; }
	}
	return max;
}

int main()
{	
	int num;
	printf("사람 수 : "); scanf_s("%d", &num);
	int* height = calloc(num, sizeof(int));
	printf("%d 명의 키 입력...\n", num);
	for (int i = 0; i < num; i++) {
		printf("[%d] : ", i + 1);
		scanf_s("%d", &height[i]);
	}
	printf("height max : %d", maxof(height,num));
	free(height);
	return 0;
}

/*
	
*/
