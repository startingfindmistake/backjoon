#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	//�ڵ��� ���� �ݺ������� n * n�� �����
	printf("%lld\n", (long long)n * n);	//n * n�� long long���� ó��

	//�ð� ���⵵�� O(n^2)=> ���׽��� �ְ����� ������ 2
	printf("2\n");

	return 0;
}