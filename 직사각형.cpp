//기하: 직사각형과 삼각형

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int A, B;

	//입력 받기
	scanf("%d", &A);
	scanf("%d", &B);

	// 넓이 계산 및 출력
	printf("%d\n", A * B);

	return 0;
}
