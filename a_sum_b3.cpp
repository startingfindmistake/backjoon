#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int A, B;

    for (;;) {      //무한루프 => 루프에서 벗어나려면 루프 내부에서 처리
        scanf("%d %d", &A, &B);
        if (A == 0 && B == 0) {     //break문으로 빠져나간다
            break;
        }
        printf("%d\n", A + B);
    }

    return 0;
}
