#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<math.h>
#include<string.h>
#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
void triangleLB(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) { printf(" *"); }
		printf("\n");
	}
}
void triangleLU(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = n+1-i; j >= 1; j--) { printf(" *"); }
		printf("\n");
	}
}
void triangleRU(int n) {
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < i; k++) { printf("  "); }
		for (int j = n + 1 - i; j >= 1; j--) { printf(" *"); }
		printf("\n");
	}
}
void triangleRB(int n) {
	for (int i = 1; i <= n; i++) {
		for (int k = n - i; k >= 1; k--) { printf("  "); }
		for (int j = 1; j <= i; j++) { printf(" *"); }
		printf("\n");
	}
}
int main()
{	
	int n;
	char arr[10];
	
	do {
		printf("몇 단 삼각형입니까? : "); scanf_s("%d", &n);
	} while (n<=0);
	
	printf("mode select : "); 

	scanf_s("%s", arr,sizeof(arr));			//gets_s(arr,sizeof(arr));		//scanf_s("%s", arr);

	printf("%s\n", arr);
	if (strcmp(arr, "LB") == 0) {
		triangleLB(n);
	}
	else if (strcmp(arr, "LU") == 0) {
		triangleLU(n);
	}
	else if (strcmp(arr, "RU") == 0) {
		triangleRU(n);
	}
	else if (strcmp(arr, "RB") == 0) {
		triangleRB(n);
	}
	else {
		printf("error occurs...");
	}
	
	return 0;
}

/*

*/
