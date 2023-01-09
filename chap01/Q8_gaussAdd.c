#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{	
	int n;
	puts("1~n sum...");
	printf("input n : ");
	scanf_s("%d",&n);

	int i, sum = 0,divNby2;
	divNby2 = n / 2;
	printf("%d\n", divNby2);

	if (n%2 == 1) {
		//홀수
		for (int j = 0; j <= divNby2; j++) { sum += n; }
	}
	else {
		//짝수
		for (int j = 0; j <= divNby2-1; j++) { sum += n; }
		sum += divNby2;
	}
	
	printf("GAUSS_ADD 1~n : %d", sum);

	return 0;
}

/*

*/
