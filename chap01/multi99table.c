#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<math.h>

int main()
{	
	printf("----곱셈표----\n");
	for (int i = 1; i <= 9;i++) {
		for (int j = 1; j <= 9;j++) {
			printf("% 3d", i * j);		//% 3d 가 3만큼 뒤에서부터 수를 채우는??
		}
		//printf("\n");
		putchar('\n');
	}
	return 0;
}

/*
	
*/
