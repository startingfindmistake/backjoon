// ���� ����

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);	//�ּҸ� �Է� �޴´�

	if (a >= 90) {
		printf("A");	//A ����
	}

	else if (a >= 80) {
		printf("B");	//b ����
	}

	else if (a >= 70) {
		printf("C");	//c ����
	}

	else if (a >= 60) {
		printf("D");	//d ����
	}

	else
		printf("F");		//�������� F�����̴�.

	return 0;
}