//2���� �迭
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[9][9];			//9 * 9ũ���� 2���� �迭 ����
	int max = 0;			//�ִ��� ������ ���� (0���� �ʱ�ȭ)
	int maxRow = 0, maxCol = 0;	//�ִ��� ��ġ�� ������ ���� (��, ��)

	//2���� �迭 �Է� �ޱ�
	for (int i = 0; i < 9; i++) {			//��: 0~8
		for (int j = 0; j < 9; j++) {		//�� 0~8
			scanf("%d", &arr[i][j]);		// �� ��� �Է�

			//�Է°� ���ÿ� �ִ� ����
			if (arr[i][j] > max) {
				max = arr[i][j];		//���ο� �ִ� ����
				maxRow = i;				//���� �� �ε��� ����
				maxCol = j;				//���� �� �ε��� ����
			}
		}
	}

	//�ִ� ���
	printf("%d\n", max);
	//��� �� ��ȣ�� 1���� �����ϹǷ� +1 �ؼ� ���
	printf("%d %d\n", maxRow + 1, maxCol + 1);

	return 0;
}