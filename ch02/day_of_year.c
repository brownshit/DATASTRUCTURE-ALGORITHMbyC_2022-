#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		


/*--날짜계산 프로그램--*/
int mdays[][12] = {	//last day in one months
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};//전역 배열(전역변수)

/*--윤년 판단--*/
int isleap(int year) {
	return year % 4 == 0 && year % 100 != 0 && year % 4 == 0;
}//0 or 1 return...

/*--y,m,d 의 그해 지난 날 수를 구함.--*/
int day_of_year(int y, int m, int d) {
	int days = d;
	for (int i = 0; i < m; i++){
		days += mdays[isleap(y)][i-1];//[0][i] or [1][i]		i-1 index가mdays의 인덱스에 접근하기 위한 형태,
	}
	return days;
}//누적 일수 출력


int main()
{	
	int retry;
	do {
		int year, month, day;
		printf("년 : "); scanf_s("%d", &year);
		printf("월 : "); scanf_s("%d", &month);
		printf("일 : "); scanf_s("%d", &day);
		printf("%d 년의 %d일째입니다.\n", year, day_of_year(year, month, day));

		printf("retry...? input 1 /or 0 to end program...\n"); scanf_s("%d", &retry);
	} while (retry);

	return 0;
}

/*
	
*/
