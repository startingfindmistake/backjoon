//���ǹ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int A, B;

	while (1) {
		scanf("%d %d", &A, &B);		//�� �� �Է�

		// ���� ����: 0 0�� �ԷµǸ� ���� ����
		if (A == 0 && B == 0) break;

		//������� �Ǵ�: B�� A�� ��� -> A�� B�� ���
		if (B % A == 0) {
			printf("factor\n");
		}
		//������� �Ǵ�: A�� B�� ��� -> A�� B�� ���
		else if (A % B == 0) {
			printf("multiple\n");
		}
		// �� �� �ƴ� ���
		else {
			printf("neither\n");
		}
	}

	return 0;
}