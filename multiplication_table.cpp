//구구단
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N;
	scanf("%d", &N);	//N 입력

	if (N >= 1 && N <= 9) {
		for (int i = 1; i <= 9; i++) {
			printf("%d * %d = %d\n", N, i, N * i);
		}
	} 
	else {
		printf("1 이상 9 이하의 숫자를 입력하세요.\n");

	}
	return 0;
}