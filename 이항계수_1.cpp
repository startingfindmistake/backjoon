/*
�� ������ �־��� �ڿ��� N�� ���� K�� ���� ���� ���
binomNK�� ����ϴ� ���Դϴ�.
*/


#include <stdio.h>

// ���丮���� ����ϴ� �Լ�
// n: ���丮���� ����� ���� (0 �̻�)
// ��ȯ��: n�� ���丮�� ��

long long factorial(int n) {
	if (n < 0) {	//���� ���丮���� ���ǵ��� ���� (���� ���ǻ� �߻����� ����)
		return -1;		// ���� ��
	}
	if (n == 0) {
		return 1;
	}
	long long result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}


int main() {
	int n, k;

	// ����ڷκ��� N�� K�� �Է¹���
	scanf("%d %d", &n, &k);

	// N�� K�� ��ȿ�� �˻� (������ ���� ���ǿ� ����)
	// 1 <= N <= 10, 0 <= K <= N
	if (n < 1 || n > 10 || k < 0 || k > n) {
		//printf("�Է� ���� ����\n");		//���� ���������� �̷� ��츦 ������� ����
		return 1;	// ���� �߻� �� ������ ����
	}


	// ���� ��� ���: N! / (k! * (N-K)!)
	long long numerator = factorial(n);
	long long denominator_k = factorial(k);
	long long denominator_n_minus_k = factorial(n - k);

	// �и� 0�� �Ǵ� ���� K�� N - K�� ������ ���ε�, factorial �Լ��� �Է� ������ �ǹ�����
	// ����, factorial(0)�� 1�̹Ƿ� 0���� ������ ������ �߻����� ����
	if (denominator_k == 0 || denominator_n_minus_k == 0) {



		return 1;
	}

	long long binomial_coefficient = numerator / (denominator_k * denominator_n_minus_k);

	// ��� ���
	printf("%lld\n", binomial_coefficient);

	return 0;	// ���α׷� ���� ����

}