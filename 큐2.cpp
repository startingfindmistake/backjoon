/*
�� ������ ������ �����ϴ� ������ �����ϰ�, �־��� ����� ó���ϴ� �����Դϴ�.
������ ���Լ���(LIFO, Last-In, First-Out) �ڷᱸ����, ���� �������� ���Ե� ���Ұ� ���� ���� �����˴ϴ�


*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp �Լ��� ����ϱ� ���� ����

#define MAX_QUEUE_SIZE 2000000 // �������� N�� �ִ밪�� 2,000,000�̹Ƿ� ť�� �ִ� ũ�⵵ �̿� �°� ����

int queue[MAX_QUEUE_SIZE]; // ������ ������ ť �迭
int front_idx = 0;         // ť�� ���� �� ������ �ε���
int rear_idx = -1;         // ť�� ���� �� ������ �ε��� (�ƹ��͵� ���� �� -1)
int count = 0;             // ť�� ����ִ� ������ ����

// push X: ���� X�� ť�� �ִ� �����̴�.
void push(int x) {
    if (count >= MAX_QUEUE_SIZE) { // ť�� �� á���� Ȯ�� (�� ���������� ��� ����ŭ�� �־����Ƿ� ��ǻ� �� �� ���� ����)
        // printf("Queue is full\n");
        return;
    }
    rear_idx = (rear_idx + 1) % MAX_QUEUE_SIZE; // rear �ε����� ���� ��ġ�� �̵� (���� ť)
    queue[rear_idx] = x;                       // �ش� ��ġ�� x�� ����
    count++;                                   // ť�� ���� ���� ����
}

// pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int pop() {
    if (count == 0) { // ť�� ����ִ��� Ȯ��
        return -1;
    }
    int val = queue[front_idx];                // ���� ���� ���Ҹ� ������
    front_idx = (front_idx + 1) % MAX_QUEUE_SIZE; // front �ε����� ���� ��ġ�� �̵� (���� ť)
    count--;                                   // ť�� ���� ���� ����
    return val;
}

// size: ť�� ����ִ� ������ ������ ����Ѵ�.
int size() {
    return count;
}

// empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
int empty() {
    if (count == 0) {
        return 1; // ��������� 1 ��ȯ
    }
    return 0; // ������� ������ 0 ��ȯ
}

// front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int front() {
    if (count == 0) { // ť�� ����ִ��� Ȯ��
        return -1;
    }
    return queue[front_idx]; // ���� ���� ���Ҹ� ��ȯ (�������� ����)
}

// back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int back() {
    if (count == 0) { // ť�� ����ִ��� Ȯ��
        return -1;
    }
    return queue[rear_idx]; // ���� ���� ���Ҹ� ��ȯ (�������� ����)
}

int main() {
    int n; // ����� ��
    scanf("%d", &n);

    char command_str[10]; // ��� ���ڿ��� ������ �迭 (��: "push", "pop" ��)

    for (int i = 0; i < n; i++) {
        scanf("%s", command_str); // ��� ���ڿ��� �Է¹���

        if (strcmp(command_str, "push") == 0) {
            int x;
            scanf("%d", &x);
            push(x);
        }
        else if (strcmp(command_str, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(command_str, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(command_str, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(command_str, "front") == 0) {
            printf("%d\n", front());
        }
        else if (strcmp(command_str, "back") == 0) {
            printf("%d\n", back());
        }
    }

    return 0; // ���α׷� ���� ����
}