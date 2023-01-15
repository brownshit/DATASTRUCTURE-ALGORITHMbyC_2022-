#include<stdio.h>
#include<stdlib.h>		//for malloc and free
//#include<time.h>

#define CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
/*===x,y교환하는 매크로함수===*/
//#define swap(type,x,y) do{type t = x; x = y; y = t; }while(0)//{type t = x; x = y; y = t;}		

int sum(int x1, int x2) {
	return x1 + x2;
}
int mul(int x1, int x2) {
	return x1 * x2;
}

/*아래의 함수 인자는 다른 함수의 함수 포인터를 인자로 가진다.*/
void kuku(int(*calc)(int, int)) {
	//calc는 함수 포인터를 인자로 가져서 
	//함수 호출시 인자로 다른 함수가 들어간다.

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++)
			printf("%3d", (*calc)(i, j));		//calc로 전달되는 다른 함수를 통해 연산을 진행한다.
		putchar('\n');//개행.
	}
}

/*매우 깔끔하게 프로그램을 짤 수 있다는 장점이 있다.*/
int main() {
	puts("덧셈표");
	kuku(sum); //인자로 함수포인터를 전달.
	puts("\n곱셈표");
	kuku(mul);
	return 0;
}


/*
	for(;1;){
		//이것도 무한루프이다. while(1){ ... }같은.
	}
*/
