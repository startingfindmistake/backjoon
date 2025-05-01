//별찍기
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int a, i , j;			// 정수형 변수 정렬
	scanf("%d", &a);		// 정수를 입력 받는다.
	
	for (i = 1; i <= a; i++) {			//반복문으로 밑줄로 내려가기
		for (int j = 0; j < i; j++) {	//반복문으로 가로 별을 찍는다.
			printf("*");
		}
		printf("\n");
	}
	return 0;
}