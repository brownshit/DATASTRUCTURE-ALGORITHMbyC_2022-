
#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
//   _CRT_SECURE_NO_WARNINGS 프로젝트 속성 c/c++ 전처리기 에 추가하면 전처리기를 따로 안써도 된다.
#include<stdio.h>
#include<stdlib.h>      //for malloc and free
#include<string.h>
//#include<time.h>

/*도수 정렬함수(배열의 요솟값은 0 이상 max이하)*/

void counting(int a[], int n, int max) {
	//누적 도수... 0~max까지의 수를 나타내기 위해 max+1까지 인덱스를 사용한다.
	int* f = calloc(max + 1, sizeof(int));

	//목적배열
	int* b = calloc(n, sizeof(int));

	//step.0...0 initialization
	for (int i = 0; i <= max; i++) f[i] = 0;

	//step.1...도수 분포표
	for (int i = 0; i < n; i++)f[a[i]]++;		//a의 value가 f의 index가 되고, 값이 occur시 하나씩 증가.

	//step.2...누적 도수분포표
	for (int i = 1; i <= max; i++) f[i] += f[i - 1];

	//step.3...목적배열 b의 이용...!
	for (int i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];	//page.280

	//step.4...copy b to a
	for (int i = 0; i < n; i++) a[i] = b[i];		//덮어쓰기
}

int main() {
	int nx;
	const int max = 100;
	puts("도수 정렬...");
	printf("요소 개수 : "); scanf_s("%d", &nx);
	int* x = calloc(nx, sizeof(int));
	printf("0 ~ %d 범위 내의 %d개 정수 input...\n", max, nx);
	for (int i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i); scanf_s("%d", &x[i]);
		} while (x[i]<0 ||x[i]>max);		//해당 조건이면 반복한다.
	}

	counting(x, nx, max);
	puts("오름차순 정렬 완료,,,!");

	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
	return 0;
}
