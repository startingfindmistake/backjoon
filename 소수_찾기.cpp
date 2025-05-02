#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // 제곱근 함수 sqrt() 사용

// 소수 판별 함수: 소수이면 1, 아니면 0 반환
int isPrime(int n) {
	if (n < 2) return 0;	//0과 1은 소수가 아님
	for (int i = 2; i <= sqrt(n); i++) {	//2부터 루트n까지 나눠봄
		if (n % i == 0) return 0;	//나누어 떨어지면 소수 아니
	}
	return 1; //위 조건을 모두 통과하면 소수
}

int main(void) {
	int N; //수의 개수를 저장할 변수
	int count = 0;	// 소수의 개수를 세기 위한 변수

	scanf("%d", &N); // 사용자로부터 수의 개수 입력 받기

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);	// 각가의 수 입력받기
		if (isPrime(num)) {
			count++;	//소수이면 count증가
		}
	}

	printf("%d\n", count);	//소수의 개수 출력

	return 0;
}