#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N;	//소인수분해할 정수를 저장할 변수

	scanf("%d", &N);	//사용자로부터 정수 입력 받기

	// 예외처리: N이 1인 경우는 소인수분해 결과가 없으므로 바로 종료
	if (N == 1) return 0;

	//2부터 시작해서 N의 제곱근까지의 수로 나누어봄
	//i*i <= N 조건은 i <= sqrt(N)과 같음 (성능을 위해 루트 대신 제곱 사용)
	for (int i = 2; i * i <= N; i++) {
		//현재 i가 N을 나눌 수 있을 때까지 반복
		while (N % i == 0) {
			printf("%d\n", i);	//i는 소인수이므로 추력
			N /= i; //N을 i로 나누고 그 결과로 다시 갱신
		}
	}

	if (N > 1) {
		printf("%d\n", N); // 남아 있는 소수를 출력
	}

	return 0; // 프로그램 정상 종료

	//위 반복문이 끝난 후 N이 1보다 크면, 그 자체가 소수이므로 
}