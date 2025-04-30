//오븐 타이머
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



int main(void)
{
    int hours, minute, oven_minute;
    scanf("%d %d", &hours, &minute);     // 현재 시각 입력
    scanf("%d", &oven_minute);           // 오븐 조리 시간 입력

    minute += oven_minute;               // 분에 조리 시간 추가

    // 분이 60 이상이면 시(hour)에 넘기기
    if (minute >= 60) {
        hours += minute / 60;            // 넘긴 시간만큼 시 증가
        minute = minute % 60;            // 남은 분
    }

    // 시가 24 이상이면 시계를 0부터 다시 시작
    if (hours >= 24) {
        hours = hours % 24;
    }

    printf("%d %d\n", hours, minute);    // 종료 시각 출력
    return 0;
}
