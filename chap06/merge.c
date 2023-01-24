#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

static int* buff;	//작업용 배열.

static void  __mergesort(int a[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		int p = 0; 
		int i; 
		int j = 0;
		int k = left;
		__mergesort(a, left, center);		//좌측 배열 정렬
		__mergesort(a, center+1,right);		//우측 배열 정렬

		//앞부분과 뒷부분의 병합
		
		//a의 앞부분을 버퍼에 넣기
		for (i = left; i <= center; i++)		//center까지
			buff[p++] = a[i];

		//a앞부분(버퍼랑), 앞의 반복문에서 같은 변수i를 동시 증가시켜, 앞부분과 뒷부분의 크기비교 후 a에 작은수부터 쌓아넣기.
		while (i <= right && j < p)				//right까지
			a[k++] = ((buff[j] <= a[i]) ? buff[j++] : a[i++]);

		//남은 수 처리(버퍼에 남은 수)
		while (j < p)
			a[k++] = buff[j++];
	}
}

int mergesort(int a[], int n) {
	if ((buff = calloc(n, sizeof(int))) == NULL)
		return -1;
	__mergesort(a, 0, n - 1);
	free(buff);
	return 0;
}

int main() {
	int nx;
	puts("병합정렬");
	printf("요소개수 : ");
	scanf_s("%d", &nx);
	int* x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i); scanf_s("%d", &x[i]);
	}
	mergesort(x, nx);
	puts("오름차순 정렬완료...");

	for (int i = 0; i < nx; i++)
		printf("x[%d] : %d\n", i, x[i]);
	free(x);

	return 0;
}
