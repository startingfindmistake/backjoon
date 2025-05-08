/*
- 주어진 보드에서 8x 8크기의 체스판을 잘라낼 수 있습니다
- 체스판은 두 가지 색상 패턴으로 칠할 수 있습니다.
1. 좌측 상단이 w로 시작하는 체스판
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
...

2. 좌측 상단이 'B'로 시작하는 체스판
BWBWBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
...

- 주어진 보드에서 임의의 8 x 8 영역을 선택하여, 두 가지 패턴으로 칠해지는 비용을 계산
- 두 패턴 중 적은 비용(다시 칠해야 하는 칸의 수)을 선택합니다.


알고리즘 분석
- 보드의 크기가 N x M일때
	- 가능한 8x8 크기 영역의 시작 좌표는 (0, 0)부터 (N - 8, M - 8)까지 입니다.
	- 각 영역마다 두 가지 패턴(W 시작, B 시작)으로 다시 칠하는 비용을 계산합니다.
	- 가장 적은 비용을 기록하여 출력합니다


3. 시간 복잡도
- O((N - 7) x (M - 7) x 64) = O(N x M)
- N, M <= 50이므로, 최대 50 x 50 = 2500 반복입니다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// 두 가지 체스판 패턴 (8x8)
char whiteFirst[8][9] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

char blackFirst[8][9] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

// 함수 8x8 영역의 다시 칠해야 하는 비용을 계산
int calculate_repaint(char board[50][50], int start_row, int start_col) {
    int white_count = 0;
    int black_count = 0;

    // 8x8 영역을 탐색
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            
            //현재 좌표의 색이 whiteFirst와 blackFirst 패턴 중 어디에 맞는지 확인
            if (board[start_row + i][start_col + j] != whiteFirst[i][j])
                white_count++;
            if (board[start_row + i][start_col + j] != blackFirst[i][j])
                black_count++;
        }
    }

    // 두 패턴 중 적은 비용을 반환
    return MIN(white_count, black_count);
}



int main() {
    int N, M;
    char board[50][50];

    // 보드 크기 입력
    scanf("%d %d", &N, &M);


    // 보드 상태 입력
    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    //long long으로 변경하여 오버플로우 방지
    long long min_repaint = 64;       // 8 x 8에서 최대 다시 칠해야 하는 경우

    // 모든 8 x 8 영역 탐색
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            // 각  8 x 8  영역의 다시 칠할 최소 비용을 계산
            int repaint = calculate_repaint(board, i, j);
            if (repaint < min_repaint) {
                min_repaint = repaint;
            }
        }
    }

    //결과 출력
    printf("%d\n", min_repaint);
    return 0;
}