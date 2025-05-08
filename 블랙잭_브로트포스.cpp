//브로트포스 알고리즘
/*
- 주어진 카드 중에서 3장을 선택하여 세 카드의 합이 M을 넘지 않으면서 최대한
M에 가까운 값을 구하는 문제

- N장의 카드 중 3장을 선택하는 조합 문제로, 모든 가능한 3장의 조합을 확인하여
조건에 맞는 최적의 값을 찾습니다.

*/

/*
알고리즘 (Brute Force - 완전 탐색)
입력 처리:

카드의 개수 N과 목표 값 M을 입력받습니다.

N개의 카드 숫자를 배열에 저장합니다.

3중 반복문을 사용하여 조합 확인:

첫 번째 카드 선택: 첫 번째 반복문 (i)

두 번째 카드 선택: 두 번째 반복문 (j), j > i로 설정

세 번째 카드 선택: 세 번째 반복문 (k), k > j로 설정

이렇게 하면 모든 가능한 3장의 조합을 확인할 수 있습니다.

카드 합 계산:

선택된 3장의 카드 합을 계산합니다.

합이 M을 초과하지 않으면:

현재 최적 값 (best_sum)과 비교하여 더 큰 값을 저장합니다.

결과 출력:

가장 큰 합(best_sum)을 출력합니다.

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//메인 함수
int main(void) {
	int N, M;
	int cards[100];


	// 입력 받기 (카드 개수 N, 목표 값 M)
	scanf("%d %d", &N, &M);

	//카드 숫자 입력 받기
	for (int i = 0; i < N; i++) {
		scanf("%d", &cards[i]);
	}

	int best_sum = 0;	//M을 넘지 않으면서 최대한 가까운 합

	// 3중 반복문으로 3장의 카드 조합 확인
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int current_sum = cards[i] + cards[j] + cards[k];

				//M을 넘지 않으면서 더 큰 합을 찾으면 갱신
				if (current_sum <= M && current_sum > best_sum) {
					best_sum = current_sum;
				}
			}
		}
	}

	//결과 출력
	printf("%d\n", best_sum);
	return 0;
}