#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char word[101];	// �ܾ�� �ִ� 100���̹Ƿ� �ι��� ������ 101ĭ �迭 ����

	scanf("%s", word);	//���ڿ� �Է� �ޱ�

	int length = strlen(word);	// �Է¹��� ���ڿ��� ���̸� ���

	printf("%d\n", length);	//���� ���

	return 0;	//���α׷� ����
}