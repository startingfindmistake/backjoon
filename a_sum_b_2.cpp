#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;

	while (1) {
		scanf("%d %d", &a, &b);

		// 종료 조건
		if (a == 0 && b == 0) {
			break;
		}

		//결과 출력
		printf("%d\n", a + b);
	}

	return 0;
}