#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		//���ڿ� ���� �Լ� ���

int main(void) {
	int T;	//�׽�Ʈ ���̽� ��
	scanf("%d", &T);	//ù �ٿ��� �׽�Ʈ ���̽� �� �Է�

	//T���� �׽�Ʈ ���̽� ó��
	for (int t = 0; t < T; t++) {
		int R;		//�ݺ� Ƚ��
		char S[21];	// �ִ� ���� 20�̹Ƿ� 21ĭ Ȯ��
		scanf("%d %s", &R, S);	//�ݺ� Ƚ���� ���ڿ� �Է�

		int len = strlen(S);	//���ڿ� ���� ���


		// ���ڿ��� �� ���ڿ� ���� �ݺ� ó��
		for (int i = 0; i < len; i++) {
			// �ش� ���ڸ� r�� �ݺ� ���
			for (int j = 0; j < R; j++) {
				printf("%c", S[i]);	//�� ���ڸ� R�� �ݺ� ���
			}
		}
		printf("\n");	 // �� �׽�Ʈ ���̽� �� �ٹٲ�
	}

	return 0;	//���α׷� ����
}