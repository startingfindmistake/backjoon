
#include<stdio.h>

// MenOfPassion 함수: 수행 횟수를 계산하는 함수
long long MenOfPassion(int n) {
	long long count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				count += 1;	//실제 곱셈 대신 수행 횟수만 증가
			}
		}
	}
	return count;
}

int main(void) {
	int n;
	scanf("%d", &n);

	// 코드1의 수행 횟수 계산
	long long count = MenOfPassion(n);

	// 결과 출력
	printf("%lld\n", count);
	printf("3\n");	//수행 시간이 n^3에 비례하므로 최고차항 차수는 3 입니다.

	return 0;
}