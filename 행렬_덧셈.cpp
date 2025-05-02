//2차원 배열

#define _CRT_SECURE_NO_WARNINGS  // Visual Studio에서 scanf 경고 방지
#include <stdio.h>

int main() {
	int N, M;	//N: 행의 개수, M: 열의 개수

	// 사용자로부터 행렬의 크기 N과 M을 입력받음
	scanf("%d %d", &N, &M);

	// 두 행렬 A, B와 결과 행렬 result 선언 (모두 최대 100 x 100 크기)
	int A[100][100];
	int B[100][100];
	int result[100][100];

	// ========================
	// 행렬 A 입력 받기
	// ========================

	for (int i = 0; i < N; i++) {		// 각 행 반복
		for (int j = 0; j < M; j++) {	// 각 열 반복
			scanf("%d", &A[i][j]);		//A[i][j] 원소 입력
		}
	}


	// ========================
	// 행렬 B 입력 받기
	// ========================
	for (int i = 0; i < N; i++) {	//각 행 반복
		for (int j = 0; j < M; j++) {	//각 열 반복
			scanf("%d", &B[i][j]);		//B[i][j]
		}
	}

	// ========================
	// A와 B의 같은 위치의 값을 더해서 result에 저장
	// ========================

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result[i][j] = A[i][j] + B[i][j];	//A와 B의 해당 위치 원소 합산
		}
	}

	// ========================
	// 결과 행렬 출력
	// ========================

	for(int i = 0; i < N; i++) {		//각 행 반복
		for (int j = 0; j < M; j++) {	//각 열 반복
			printf("%d ", result[i][j]);	//result[i][j] 값 출력, 공백으로 구분
		}
		printf("\n");	// 한 행이 끝나면 줄바꿈
	}

	return 0;	// 프로그램 종류

}