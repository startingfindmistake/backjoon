//2차원 배열
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[9][9];			//9 * 9크기의 2차원 배열 선언
	int max = 0;			//최댓값을 저장할 변수 (0으로 초기화)
	int maxRow = 0, maxCol = 0;	//최댓값의 위치를 저장할 변수 (행, 열)

	//2차원 배열 입력 받기
	for (int i = 0; i < 9; i++) {			//행: 0~8
		for (int j = 0; j < 9; j++) {		//열 0~8
			scanf("%d", &arr[i][j]);		// 각 요소 입력

			//입력과 동시에 최댓값 갱신
			if (arr[i][j] > max) {
				max = arr[i][j];		//새로운 최댓값 지정
				maxRow = i;				//현재 행 인덱스 저장
				maxCol = j;				//현재 열 인덱스 저장
			}
		}
	}

	//최댓값 출력
	printf("%d\n", max);
	//행과 열 번호는 1부터 시작하므로 +1 해서 출력
	printf("%d %d\n", maxRow + 1, maxCol + 1);

	return 0;
}