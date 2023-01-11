#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>
#define VMAX 21		//시력의 최댓값 : 2.1 x 10		상수의 정의.

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		

/*--구조체 배열로 구현하기--*/

typedef struct {
	char	name[20];	//이름
	int		height;		//키
	double	vision;		//시력
}Physcheck;

//키의 mean value.
double ave_height(const Physcheck dat[], int n) {//n은 사람수.
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += dat[i].height;
	}
	return sum / n;
}

//시력분포
void dist_vision(const Physcheck dat[], int n, int dist[]) {//dist 0.1간격으로 0.0~2.1까지의 시력값에 분포된 인원 수.
	for (int i = 0; i < VMAX; i++) {//dist배열의 초기화. main에서 만들기만 하고 넘어오는 dist배열.
		dist[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0) {//10.0 인 이유는 실수형 나눗셈을 하기 위해서.
			dist[(int)(dat[i].vision)*10]++;		//(dat[i].vision)*10		얘가 인덱스이다.
		}
	}
}

int main()
{	
	Physcheck x[] = {//구조체의 데이터는 인덱싱으로 판별하기 때문에 굳이 내부의 데이터가 같다고 해서 망가지지 않는다.
		{"박현규",162,0.3},
		{"함진아",173,0.7},
		{"최윤미",175,2.0},
		{"홍연의",162,1.5},
		{"이수진",168,0.4},
		{"김영준",174,1.2},
		{"박용규",169,0.8}
	};

	int nx = sizeof(x) / sizeof(x[0]);		//이 구문을 통해 x요소개수를 알 수 있다.
	int vdist[VMAX];

	puts("=======[신체검사표]=======");
	puts("	이름		키	시력	");
	puts("==========================");
	for (int i = 0; i < nx; i++) {
		printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision); 
		//% 뒤에 오는 수는 blank를 갖기 위한 수이고, f앞의 .1은 소수점 1자리까지라는 의미. 
	}
	printf("\n평균 키 : %5.1f cm\n", ave_height(x, nx));
	dist_vision(x, nx, vdist);	//vdist를 완성 시켜주는 함수이다.
	for (int i = 0; i < VMAX; i++) {
		printf("%3.1f ~ :%2d 명\n", i / 10.0, vdist[i]);
	}
	return 0;
}

/*
	
*/
