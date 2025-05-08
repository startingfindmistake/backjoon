#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	//코드 1은 항상 1번 실행됨
	printf("1\n");

	//시간 복잡도는 o(1), 즉 최고차항의 차수는 0
	printf("0\n");


	return 0;
}