/*
이 문제는 정수를 저장하는 스택을 구현하고, 주어진 명령을 처리하는 문제입니다
스택은 후입선출(LIFO, Last-In First-Out) 자료구조로, 가장 마지막에 삽입된 원소가
가장 먼저 삭제 됩니다.

C언어에서는 배열을 사용하여 스택을 구현할 수 있습니다. 스택의 맨 위를 가리키는 인덱스 변수 (예: top)를 사용합니다.

push (1 X): stack[++top] = X;
pop (2): if (top == -1) return -1; else return stack[top--];
size (3): return top + 1;
empty (4): return (top == -1) ? 1 : 0;
top (5): if (top == -1) return -1; else return stack[top];
초기에는 top을 -1로 설정하여 스택이 비어있음을 나타냅니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>		// malloc, free 함수를 사용하기 위해 포함 (필요시)

#define MAX_STACK_SIZE 1000000 // 문제에서 N의 최대값이 1,000,000 이므로 스택의 최대 크기도 이에 맞게 설정

int stack[MAX_STACK_SIZE];		// 정수를 저장할 스택 배열
int top = -1; // 스택의 가장 위 원소의 인덱스를 나타내는 변수, -1이면 비어있음을 의미

// 1 x: 정수 X를 스택에 넣는다.
void push(int x) {
	if (top >= MAX_STACK_SIZE - 1) {	// 스택이 꽉 찼는지 확인
		// 실제 문제에서는 스택 오버플로우 처리가 명시되어 있지 않으나, 방어적으로 작성
		// printf("Stack Overflow\n");
		return;
	}
	stack[++top] = x; // top을 증가시키고 해당 위치에 x를 저장
}

// 2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
int pop() {
	if (top == -1) {		// 스택이 비어있는지 확인
		return -1;			// 비어 있다면, -1을 출력합니다
	}
	return stack[top--];		// 현재 스택의 가장 윗부분 top의 원소를 반환하고 top을 감소시킴
}


// 3: 스택에 들어있는 정수의 개수를 출력한다.
int size() {
	return top + 1;		// top은 인덱스이므로 개수는 top + 1
}

// 4: 스택이 비어있으면 1, 아니면 0을 출력한다.
int empty() {
	if (top == -1) {
		return 1;		// 비어있으면 1 반환
	}
	return 0;		// 비어있지 않으면 0 반환
}

// 5. 스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 -1을 대신 출력한다.
int peek() {		// 문제에서는 'top'이라는 용어 대신 'peek'으로 함수명을 사용하기도 함
	if (top == -1) {		// 스택이 비어있는지 확인
		return -1;			// 비어있다면, -1을 출력합니다
	}
	return stack[top];			// 비어있지 않다면, 스택의 가장 윗부분(top)에 있는 정수를 가져와 출력한다(이때, 정수를 스택에서 제거하지 않습니다)
}


int main() {
	int n;		// 명령의 수
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int command;
		scanf("%d", &command);	// 명령을 입력받음

		switch (command) {
		case 1: {		// 정수 X를 스택에 넣는 명령
			int x;
			scanf("%d", &x);
			push(x);
			break;
		}
		case 2: {		// 스택에서 맨 위 정수를 빼고 출력하는 명령
			printf("%d\n", pop());
			break;
		}
		case 3: {		// 스택이 들어있는 정수의개수를 출력하는 명령
			printf("%d\n", size());
			break;
		}
		case 4: {		// 스택이 비어있는지 여부를 출력하는 명령
			printf("%d\n", empty());
			break;
		}
		case 5: {		// 스택의 맨 위 정수를 출력하는 명령
			printf("%d\n", peek());
			break;
		}
		default:		// 유효하지 않은 명령 처리 (문제 조건상 발생하지 않을 수 있음)
			// printf("Invalid command\n");
			break;
		}
	}
	
	return 0;		//프로그램 정상 종료
}