//기하
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    int x4, y4;

    // 좌표 입력
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    // x 좌표 중 두 개가 같으면, 나머지 하나가 네 번째 점의 x 좌표
    if (x1 == x2)
        x4 = x3;
    else if (x1 == x3)
        x4 = x2;
    else // x2 == x3
        x4 = x1;

    // y 좌표도 같은 방식으로 처리
    if (y1 == y2)
        y4 = y3;
    else if (y1 == y3)
        y4 = y2;
    else // y2 == y3
        y4 = y1;


    //테스트 결과 출력(이걸로 문제를 파악한다)
    printf("x1=%d y1=%d\n", x1, y1);
    printf("x2=%d y2=%d\n", x2, y2);
    printf("x3=%d y3=%d\n", x3, y3);


    // 결과 출력
    printf("%d %d\n", x4, y4);

    return 0;
}
