
#include<stdio.h>

// MenOfPassion �Լ�: ���� Ƚ���� ����ϴ� �Լ�
long long MenOfPassion(int n) {
	long long count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				count += 1;	//���� ���� ��� ���� Ƚ���� ����
			}
		}
	}
	return count;
}

int main(void) {
	int n;
	scanf("%d", &n);

	// �ڵ�1�� ���� Ƚ�� ���
	long long count = MenOfPassion(n);

	// ��� ���
	printf("%lld\n", count);
	printf("3\n");	//���� �ð��� n^3�� ����ϹǷ� �ְ����� ������ 3 �Դϴ�.

	return 0;
}