//���� Ÿ�̸�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



int main(void)
{
    int hours, minute, oven_minute;
    scanf("%d %d", &hours, &minute);     // ���� �ð� �Է�
    scanf("%d", &oven_minute);           // ���� ���� �ð� �Է�

    minute += oven_minute;               // �п� ���� �ð� �߰�

    // ���� 60 �̻��̸� ��(hour)�� �ѱ��
    if (minute >= 60) {
        hours += minute / 60;            // �ѱ� �ð���ŭ �� ����
        minute = minute % 60;            // ���� ��
    }

    // �ð� 24 �̻��̸� �ð踦 0���� �ٽ� ����
    if (hours >= 24) {
        hours = hours % 24;
    }

    printf("%d %d\n", hours, minute);    // ���� �ð� ���
    return 0;
}
