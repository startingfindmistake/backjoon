//�����2
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int input, line_jump, space, star;
	scanf("%d", &input);
	for (line_jump = 1; line_jump <= input; line_jump++)		//1���� n
	{
		//���� ���
		for (space = 1; space <= input - line_jump; space++) {
			printf(" ");
		}
		// �� ��� (i��)
		for (star = 1; star <= line_jump; star++) {
			printf("*");
		}
		printf("\n");	//�ٹٲ�
	}
	return 0;
}