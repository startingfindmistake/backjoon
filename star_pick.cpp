//�����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int a, i , j;			// ������ ���� ����
	scanf("%d", &a);		// ������ �Է� �޴´�.
	
	for (i = 1; i <= a; i++) {			//�ݺ������� ���ٷ� ��������
		for (int j = 0; j < i; j++) {	//�ݺ������� ���� ���� ��´�.
			printf("*");
		}
		printf("\n");
	}
	return 0;
}