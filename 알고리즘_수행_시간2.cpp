#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	//이 코드는 반복문을 n번 돌면서 실행됨
	printf("%d\n", n);

	//시간 복잡도는 o(n) => 다항식의 최고차항 차수는 1
	printf("1\n");

	return 0;
}