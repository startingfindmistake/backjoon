/*
이 문제는 주어진 0보다 크거나 같은 정수 N에 대해 N 팩토리얼(N!)을 계산하고 출력하는 것입니다.


고려사항:
N의 최댓값이 20이므로, 20!의 크기를 고려해야 합니다.
20 = 2,432,902,008,176,640,000
이 값은 일반적인 32비트 정수형int 의 범위를 훨씬 초과합니다.
따라서 64비트 정수형 (long long in C)을 사용하여 결과를 저장해야 합니다


*/


#include<stdio.h>

int main() {
	int n;			// 입력받을 정수 N (0 <= N <= 20)

	// 사용자로부터 N을 입력받음
	scanf("%d", &n);

	// N!의 결과를 저장할 변수. N=20일 때 결과가 매우 크므로 long long 타입을 사용.
	long long factorial_result = 1;

	// N! 계산
	// N이 0이나 1일 경우, factorial_result는 초기값 1을 유지.
	// N이 2 이상일 경우, 2부터 N까지 곱해나감
	// (또는 i를 1부터 시작해도 동일한 결과를 얻음: for (int i = 1; i <= n; i++))
	for (int i = 2; i <= n; i++) {
		factorial_result *= i;
	}

	// 계산된 N! 값을 출력
	// long long 타입의 값을 출력할 때는 %lld 형식 지정자를 사용
	printf("%lld\n", factorial_result);

	return 0;		// 프로그램 정상 종료
}