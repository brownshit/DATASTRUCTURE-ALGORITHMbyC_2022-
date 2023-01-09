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

	int i, sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum += i;
	}
	double lognum = log10((double)sum);
	int logsum = (int)floor(lognum);
	int j = 1;
	int number = (2 * n + logsum);
	char* arr = (char*)malloc(sizeof(char) * number);
	
	while (1) {
		if (j < n) {
			arr[j] = (int)((j+1)/2); arr[j + 1] = '+';
			j = j+2;
		}
		else {
			arr[j] = (int)((j + 1) / 2);
			arr[j + 1] = '=';
			arr[j + 2] = sum;
		}
	}
	printf("%c",arr);

	free(arr);

	return 0;
}

/*

*/
