#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>		//for malloc and free
#include<math.h>

int main()
{	
	int n,digitNum;
	double tempVar;
	printf("input n : ");
	scanf_s("%d", &n);
	tempVar = log10((double)n);
	digitNum = ceil(tempVar);
	printf("%d 's digit : %d", n, digitNum);

	
	return 0;
}

/*
	
*/
