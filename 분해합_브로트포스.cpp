/*
-분해합: 주어진 수 N과 그 수를 구성하는 각 자리의 숫자의 합을 말한다
-생성자: 분해합이 N이 되는 수를 말하며, 가장 작은 생성자를 찾아야 한다.

알고리즘 분석
- N의 가능한 생성자는 N - 9 x 자리수에서 N까지 이다
이는 각 자리의 최댓값이 9이기 때문에, N에서 9 x 자리수를 빼는 범위에서 생성자를 탐색합니다

-모든 가능한 생성자를 탐색하여
	- 각 생성자의 분해합을 계산합니다.
	- 분해합이 N과 같다면, 그 생성자를 최소 생성자로 지정합니다.

시간복잡도
- O(N)으로 보일 수 있지만, 실제로는 N의 자리 수에 비례하는 O(d)가 됩니다.
d는 N의 자리수

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//분해합을 계산하는 함수
int calculate_sum(int num) {
	int sum = num;
	while (num > 0) {
		sum += num % 10;		//각 자리수를 더함
		num /= 10;				//자리수를 줄여 나감

	}
	return sum;
}

int main(void) {
	int N, result = 0;
	scanf("%d", &N);

	//가능한 최소 생성자부터 N까지 탐색
	for (int i = N - 9 * 7; i < N; i++) {
		if (i < 0) continue;	//음수는 탐색하지 않음

		// i와 분해합이 N인지 확인
		if (calculate_sum(i) == N) {
			result = i;		//첫 번째로 발견된 생성자가 가장 작음
			break;
		}
	}

	//결과 출력
	printf("%d\n", result);
	return 0;
}