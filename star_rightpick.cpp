//별찍기2
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int input, line_jump, space, star;
	scanf("%d", &input);
	for (line_jump = 1; line_jump <= input; line_jump++)		//1부터 n
	{
		//공백 출력
		for (space = 1; space <= input - line_jump; space++) {
			printf(" ");
		}
		// 별 출력 (i개)
		for (star = 1; star <= line_jump; star++) {
			printf("*");
		}
		printf("\n");	//줄바꿈
	}
	return 0;
}