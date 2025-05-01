/*
문제
총 N개의 정수가 주어졌을 때, 정수 v가 몇 개인지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수 N(1 ≤ N ≤ 100)이 주어진다. 둘째 줄에는 정수가 공백으로 구분되어져있다. 셋째 줄에는 찾으려고 하는 정수 v가 주어진다. 입력으로 주어지는 정수와 v는 -100보다 크거나 같으며, 100보다 작거나 같다.

출력
첫째 줄에 입력으로 주어진 N개의 정수 중에 v가 몇 개인지 출력한다.*/



#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int N, V, count = 0;
	int arr[100];

	scanf("%d", &N);
	//배열의 n개의 정수의 입력 받아 저장
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	//찾고자 하는 값 v를 입력받음
	scanf("%d", &V);

	//배열을 순회하면서 arr[i]가 V와 같으면 count를 1 증가시킴
	for (int i = 0; i < N; i++) {
		if (arr[i] == V) {
				count++;
		}
	}

	printf("%d\n", count);
	return 0;
}
