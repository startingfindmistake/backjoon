//�� �� ���ϱ�
//1330��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b); //�ּҸ� �Է� �޴´�.

	if (a > b) {			//if���� ����ؼ� �񱳽��� �ۼ��Ѵ�
		printf(">");		
	}
	else if (a < b) {		// �Ǵ� else if�� ����Ͽ� ���ǽ��� �ۼ�
		printf("<");
	}
	else {					// ���� ��� ������ �ƴϸ� ���
		printf("==");
	}
	return 0;
}