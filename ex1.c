#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a, b, c;
	printf("�� ������ �ִ��� ���մϴ�.\n");
	printf("a value : "); scanf_s("%d", &a);
	printf("b value : "); scanf_s("%d", &b);
	printf("c value : "); scanf_s("%d", &c);
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	printf("max value is %d\n", max);

	return 0;
}