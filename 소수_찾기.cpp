#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // ������ �Լ� sqrt() ���

// �Ҽ� �Ǻ� �Լ�: �Ҽ��̸� 1, �ƴϸ� 0 ��ȯ
int isPrime(int n) {
	if (n < 2) return 0;	//0�� 1�� �Ҽ��� �ƴ�
	for (int i = 2; i <= sqrt(n); i++) {	//2���� ��Ʈn���� ������
		if (n % i == 0) return 0;	//������ �������� �Ҽ� �ƴ�
	}
	return 1; //�� ������ ��� ����ϸ� �Ҽ�
}

int main(void) {
	int N; //���� ������ ������ ����
	int count = 0;	// �Ҽ��� ������ ���� ���� ����

	scanf("%d", &N); // ����ڷκ��� ���� ���� �Է� �ޱ�

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);	// ������ �� �Է¹ޱ�
		if (isPrime(num)) {
			count++;	//�Ҽ��̸� count����
		}
	}

	printf("%d\n", count);	//�Ҽ��� ���� ���

	return 0;
}