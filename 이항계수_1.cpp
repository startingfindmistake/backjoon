/*
이 문제는 주어진 자연수 N과 정수 K에 대해 이항 계수
binomNK를 계산하는 것입니다.
*/


#include <stdio.h>

// 팩토리얼을 계산하는 함수
// n: 팩토리얼을 계산할 정수 (0 이상)
// 반환값: n의 팩토리얼 값

long long factorial(int n) {
	if (n < 0) {	//음수 팩토리얼은 정의되지 않음 (문제 조건상 발생하지 않음)
		return -1;		// 오류 값
	}
	if (n == 0) {
		return 1;
	}
	long long result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}


int main() {
	int n, k;

	// 사용자로부터 N과 K를 입력받음
	scanf("%d %d", &n, &k);

	// N과 K의 유효성 검사 (문제의 제약 조건에 따라)
	// 1 <= N <= 10, 0 <= K <= N
	if (n < 1 || n > 10 || k < 0 || k > n) {
		//printf("입력 범위 오류\n");		//실제 문제에서는 이럴 경우를 명시하지 않음
		return 1;	// 오류 발생 시 비정상 종료
	}


	// 이항 계수 계산: N! / (k! * (N-K)!)
	long long numerator = factorial(n);
	long long denominator_k = factorial(k);
	long long denominator_n_minus_k = factorial(n - k);

	// 분모가 0이 되는 경우는 K나 N - K가 음수일 때인데, factorial 함수와 입력 조건을 ㅗ방지됨
	// 또한, factorial(0)은 1이므로 0으로 나누는 오류는 발생하지 않음
	if (denominator_k == 0 || denominator_n_minus_k == 0) {



		return 1;
	}

	long long binomial_coefficient = numerator / (denominator_k * denominator_n_minus_k);

	// 결과 출력
	printf("%lld\n", binomial_coefficient);

	return 0;	// 프로그램 정상 종류

}