// 시험 성적

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);	//주소를 입력 받는다

	if (a >= 90) {
		printf("A");	//A 학점
	}

	else if (a >= 80) {
		printf("B");	//b 학점
	}

	else if (a >= 70) {
		printf("C");	//c 학점
	}

	else if (a >= 60) {
		printf("D");	//d 학점
	}

	else
		printf("F");		//나머지는 F학점이다.

	return 0;
}