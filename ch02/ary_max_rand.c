#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

int maxof(const int a[], int n) {
	int max = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > max) max = a[i];
	return max;
}

int main()
{	
	int num;
	printf("사람 수 : ");
	scanf_s("%d", &num);
	int* height = calloc(num, sizeof(int));
	srand(time(NULL));			//시간으로 난수의 seed를 초기화.
	for (int i = 0; i < num; i++) {
		height[i] = 140 + rand() % 50;		//100 ~ 189
		printf("height[%d] = %d\n", i + 1, height[i]);
	}
	printf("max : %d\n", maxof(height, num));
	free(height);
	
	return 0;
}

/*
	
*/
