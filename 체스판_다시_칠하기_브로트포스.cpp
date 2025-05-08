/*
- �־��� ���忡�� 8x 8ũ���� ü������ �߶� �� �ֽ��ϴ�
- ü������ �� ���� ���� �������� ĥ�� �� �ֽ��ϴ�.
1. ���� ����� w�� �����ϴ� ü����
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
...

2. ���� ����� 'B'�� �����ϴ� ü����
BWBWBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
...

- �־��� ���忡�� ������ 8 x 8 ������ �����Ͽ�, �� ���� �������� ĥ������ ����� ���
- �� ���� �� ���� ���(�ٽ� ĥ�ؾ� �ϴ� ĭ�� ��)�� �����մϴ�.


�˰��� �м�
- ������ ũ�Ⱑ N x M�϶�
	- ������ 8x8 ũ�� ������ ���� ��ǥ�� (0, 0)���� (N - 8, M - 8)���� �Դϴ�.
	- �� �������� �� ���� ����(W ����, B ����)���� �ٽ� ĥ�ϴ� ����� ����մϴ�.
	- ���� ���� ����� ����Ͽ� ����մϴ�


3. �ð� ���⵵
- O((N - 7) x (M - 7) x 64) = O(N x M)
- N, M <= 50�̹Ƿ�, �ִ� 50 x 50 = 2500 �ݺ��Դϴ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// �� ���� ü���� ���� (8x8)
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

// �Լ� 8x8 ������ �ٽ� ĥ�ؾ� �ϴ� ����� ���
int calculate_repaint(char board[50][50], int start_row, int start_col) {
    int white_count = 0;
    int black_count = 0;

    // 8x8 ������ Ž��
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            
            //���� ��ǥ�� ���� whiteFirst�� blackFirst ���� �� ��� �´��� Ȯ��
            if (board[start_row + i][start_col + j] != whiteFirst[i][j])
                white_count++;
            if (board[start_row + i][start_col + j] != blackFirst[i][j])
                black_count++;
        }
    }

    // �� ���� �� ���� ����� ��ȯ
    return MIN(white_count, black_count);
}



int main() {
    int N, M;
    char board[50][50];

    // ���� ũ�� �Է�
    scanf("%d %d", &N, &M);


    // ���� ���� �Է�
    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    //long long���� �����Ͽ� �����÷ο� ����
    long long min_repaint = 64;       // 8 x 8���� �ִ� �ٽ� ĥ�ؾ� �ϴ� ���

    // ��� 8 x 8 ���� Ž��
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            // ��  8 x 8  ������ �ٽ� ĥ�� �ּ� ����� ���
            int repaint = calculate_repaint(board, i, j);
            if (repaint < min_repaint) {
                min_repaint = repaint;
            }
        }
    }

    //��� ���
    printf("%d\n", min_repaint);
    return 0;
}