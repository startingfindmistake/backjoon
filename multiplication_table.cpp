//������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N;
	scanf("%d", &N);	//N �Է�

	if (N >= 1 && N <= 9) {
		for (int i = 1; i <= 9; i++) {
			printf("%d * %d = %d\n", N, i, N * i);
		}
	} 
	else {
		printf("1 �̻� 9 ������ ���ڸ� �Է��ϼ���.\n");

	}
	return 0;
}