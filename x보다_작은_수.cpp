/*
문제
정수 N개로 이루어진 수열 A와 정수 X가 주어진다.이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 X가 주어진다. (1 ≤ N, X ≤ 10, 000)

둘째 줄에 수열 A를 이루는 정수 N개가 주어진다.주어지는 정수는 모두 1보다 크거나 같고, 10, 000보다 작거나 같은 정수이다.

출력
X보다 작은 수를 입력받은 순서대로 공백으로 구분해 출력한다.X보다 작은 수는 적어도 하나 존재한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int N, X;
	int arr[10000]; //N의 최대값 10000을 고려한 배열 선언
	int first = 1;

	//입력 받기
	scanf("%d %d", &N, &X);

	//수열 A 입력
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	//x보다 작은 수만 출력
	for (int i = 0; i < N; i++) {
		if (arr[i] < X) {
			if (!first) {
				printf(" ");	//첫 출력 이후부터 공백 출력
			}
			printf("%d", arr[i]);
			first = 0;	//첫 출력 완료
		}
	}

	printf("\n");	//출력 끝난 후 줄바꿈
	return 0;
}