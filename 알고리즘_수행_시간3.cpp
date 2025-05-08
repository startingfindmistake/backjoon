#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	//코드은 이중 반복문에서 n * n번 실행됨
	printf("%lld\n", (long long)n * n);	//n * n을 long long으로 처리

	//시간 복잡도는 O(n^2)=> 다항식의 최고차항 차수는 2
	printf("2\n");

	return 0;
}