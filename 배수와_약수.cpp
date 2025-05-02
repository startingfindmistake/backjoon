//조건문

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int A, B;

	while (1) {
		scanf("%d %d", &A, &B);		//두 수 입력

		// 종료 조건: 0 0이 입력되면 루프 종류
		if (A == 0 && B == 0) break;

		//약수인지 판단: B가 A의 배수 -> A는 B의 약수
		if (B % A == 0) {
			printf("factor\n");
		}
		//배수인지 판단: A가 B의 배수 -> A는 B의 배수
		else if (A % B == 0) {
			printf("multiple\n");
		}
		// 둘 다 아닌 경우
		else {
			printf("neither\n");
		}
	}

	return 0;
}