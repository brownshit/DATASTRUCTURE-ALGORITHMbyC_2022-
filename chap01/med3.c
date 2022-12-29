#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int midinteger(int a, int b, int c);
int main()
{	
	for (int i = 0; i < 6; i++) {
		int a, b, c;
		printf("[%d] try...input 3 numbers [ blank is essential ] : ", i+1);
		scanf_s("%d %d %d", &a, &b, &c);
		printf("during input numbers, middle number is : %d\n", midinteger(a, b, c));
	}
	return 0;
}
int midinteger(int a, int b, int c)
{
	int midvalue = a;
	if (a >= b)
	{
		if (a <= c)
		{
			midvalue = a;
		}
		else if(b>=c)
		{
			midvalue = b;
		}
		else
		{
			midvalue = c;
		}
	}
	else //a is not bigger than b
	{
		if (c >= b){
			midvalue = b;
		}
		else if (a>=c) {
			midvalue = a;
		}
		else {
			midvalue = c;
		}
	}
	return midvalue;
}
