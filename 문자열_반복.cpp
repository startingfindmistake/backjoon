#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		//문자열 관련 함수 사용

int main(void) {
	int T;	//테스트 케이스 수
	scanf("%d", &T);	//첫 줄에서 테스트 케이스 수 입력

	//T개의 테스트 케이스 처리
	for (int t = 0; t < T; t++) {
		int R;		//반복 횟수
		char S[21];	// 최대 길이 20이므로 21칸 확보
		scanf("%d %s", &R, S);	//반복 횟수와 문자열 입력

		int len = strlen(S);	//문자열 길이 계산


		// 문자열의 각 문자에 대해 반복 처리
		for (int i = 0; i < len; i++) {
			// 해당 문자를 r번 반복 출력
			for (int j = 0; j < R; j++) {
				printf("%c", S[i]);	//각 문자를 R번 반복 출력
			}
		}
		printf("\n");	 // 각 테스트 케이스 후 줄바꿈
	}

	return 0;	//프로그램 종류
}