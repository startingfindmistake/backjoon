//����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    int x4, y4;

    // ��ǥ �Է�
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    // x ��ǥ �� �� ���� ������, ������ �ϳ��� �� ��° ���� x ��ǥ
    if (x1 == x2)
        x4 = x3;
    else if (x1 == x3)
        x4 = x2;
    else // x2 == x3
        x4 = x1;

    // y ��ǥ�� ���� ������� ó��
    if (y1 == y2)
        y4 = y3;
    else if (y1 == y3)
        y4 = y2;
    else // y2 == y3
        y4 = y1;


    //�׽�Ʈ ��� ���(�̰ɷ� ������ �ľ��Ѵ�)
    printf("x1=%d y1=%d\n", x1, y1);
    printf("x2=%d y2=%d\n", x2, y2);
    printf("x3=%d y3=%d\n", x3, y3);


    // ��� ���
    printf("%d %d\n", x4, y4);

    return 0;
}
