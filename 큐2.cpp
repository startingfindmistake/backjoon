/*
이 문제는 정수를 저장하는 스택을 구현하고, 주어진 명령을 처리하는 문제입니다.
스택은 후입선출(LIFO, Last-In, First-Out) 자료구조로, 가장 마지막에 삽입된 원소가 가장 먼저 삭제됩니다


*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp 함수를 사용하기 위해 포함

#define MAX_QUEUE_SIZE 2000000 // 문제에서 N의 최대값이 2,000,000이므로 큐의 최대 크기도 이에 맞게 설정

int queue[MAX_QUEUE_SIZE]; // 정수를 저장할 큐 배열
int front_idx = 0;         // 큐의 가장 앞 원소의 인덱스
int rear_idx = -1;         // 큐의 가장 뒤 원소의 인덱스 (아무것도 없을 때 -1)
int count = 0;             // 큐에 들어있는 정수의 개수

// push X: 정수 X를 큐에 넣는 연산이다.
void push(int x) {
    if (count >= MAX_QUEUE_SIZE) { // 큐가 꽉 찼는지 확인 (이 문제에서는 명령 수만큼만 주어지므로 사실상 꽉 찰 일은 없음)
        // printf("Queue is full\n");
        return;
    }
    rear_idx = (rear_idx + 1) % MAX_QUEUE_SIZE; // rear 인덱스를 다음 위치로 이동 (원형 큐)
    queue[rear_idx] = x;                       // 해당 위치에 x를 저장
    count++;                                   // 큐의 원소 개수 증가
}

// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop() {
    if (count == 0) { // 큐가 비어있는지 확인
        return -1;
    }
    int val = queue[front_idx];                // 가장 앞의 원소를 가져옴
    front_idx = (front_idx + 1) % MAX_QUEUE_SIZE; // front 인덱스를 다음 위치로 이동 (원형 큐)
    count--;                                   // 큐의 원소 개수 감소
    return val;
}

// size: 큐에 들어있는 정수의 개수를 출력한다.
int size() {
    return count;
}

// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
int empty() {
    if (count == 0) {
        return 1; // 비어있으면 1 반환
    }
    return 0; // 비어있지 않으면 0 반환
}

// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int front() {
    if (count == 0) { // 큐가 비어있는지 확인
        return -1;
    }
    return queue[front_idx]; // 가장 앞의 원소를 반환 (제거하지 않음)
}

// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int back() {
    if (count == 0) { // 큐가 비어있는지 확인
        return -1;
    }
    return queue[rear_idx]; // 가장 뒤의 원소를 반환 (제거하지 않음)
}

int main() {
    int n; // 명령의 수
    scanf("%d", &n);

    char command_str[10]; // 명령 문자열을 저장할 배열 (예: "push", "pop" 등)

    for (int i = 0; i < n; i++) {
        scanf("%s", command_str); // 명령 문자열을 입력받음

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

    return 0; // 프로그램 정상 종료
}