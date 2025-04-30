#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int t;	//테스트 케이스 개수
	scanf("%d", &t);
	

	for (int i = 0; i < t; i++) {
		int a, b;					//
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}