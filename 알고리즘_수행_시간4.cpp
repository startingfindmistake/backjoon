#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	//�ڵ��� (n * (n - 1)) / 2�� �����
	long long count = (long long)n * (n - 1) / 2;
	printf("%lld\n", count);

	//�ð� ���⵵�� O(n^2) => ���׽��� �ְ����� ������ 2
	printf("2\n");

	return 0;
}