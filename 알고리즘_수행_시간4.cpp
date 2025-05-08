#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	//코드은 (n * (n - 1)) / 2번 실행됨
	long long count = (long long)n * (n - 1) / 2;
	printf("%lld\n", count);

	//시간 복잡도는 O(n^2) => 다항식의 최고차항 차수는 2
	printf("2\n");

	return 0;
}