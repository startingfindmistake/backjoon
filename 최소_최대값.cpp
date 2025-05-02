/*
문제
N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 
둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 
모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.

출력
첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int N;
	scanf("%d", &N);	//정수 개수 입력


	//N개의 정수를 입력받아 배열에 저장
	int arr[N];			//입력된 정수들을 저장할 배열
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);		//배열에 정수 입력
	}

	//배열의 첫 번째 값을 최솟값과 최댓값 초기값으로 설정
	int min = arr[0];
	int max = arr[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] < min) {		//현재 값이 min보다 작으면 min갱신
			min = arr[i];
		}
		if (arr[i] > max) {		//현재 값이 max보다 크면 max 갱신
			max = arr[i];
		}
	}

	printf("%d %d \n", min, max);		//최솟값과 최댓값을 출력

	return 0;
}