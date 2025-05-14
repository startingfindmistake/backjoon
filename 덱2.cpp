/*
이 문제는 정수를 저장하는 덱(Deque, Double-Ended Queue)을 구현하고,
주어진 명령을 처리하는 프로그램 입니다.
덱은 양쪽 끝(앞과 뒤)에서 모두 원소의 삽입(push)과 삭제(pop)이 가능한 자료구조

*/


#include<stdio.h>

#define MAX_DEQUE_SIZE 100000000	// 문제에서 N의 최대값이 1,000,000 이므로 덱의 최대 크기도 이에 맞게 설정

int deque[MAX_DEQUE_SIZE];			// 정수를 저장할 덱 배열
int front_idx = 0;					// 덱의 가장 앞 원소의 인덱스
int rear_idx = 0;					// 덱의 가장 뒤 원소의 인덱스
int count = 0;						// 덱에 들어있는 정수의 개수


// 1: 정수 X를 덱의 앞에 넣는다.
void push_front(int x) {
	if (count >= MAX_DEQUE_SIZE) {		// 덱이 꽉 찼는지 확인(이론상, 문제 조건에서는 N번 연산)
		printf("Deque is full\n");
		return;
	}
	if (count == 0) {
		front_idx = 0;
		rear_idx = 0;
		deque[front_idx] = x;
	}
	else {
		front_idx = (front_idx - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;		//front를 앞으로 이동
		deque[front_idx] = x;
	}
	count++;		// 원소 개수 증가
}

// 2. 정수 X를 덱의 뒤에 넣는다.
void push_back(int x) {
	if (count >= MAX_DEQUE_SIZE) {
		printf("Deque is full\n");
		return;
	}
	if (count == 0) {
		front_idx = 0;
		rear_idx = 0;
		deque[rear_idx] = x;
	} else {
		rear_idx = (rear_idx + 1) % MAX_DEQUE_SIZE;	//rear를 뒤로 이동
		deque[rear_idx] = x;
	}
	count++;			// 원소 개수 증가
}

// 3. 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
int pop_front() {
	if (count == 0) {
		return -1;
	}
	int val = deque[front_idx];		//맨 앞의 원소 가져오기
	if (count != 1) {
		front_idx = (front_idx + 1) % MAX_DEQUE_SIZE;
	}력한다.
	// 만약 원소가 하나였다면, front_idx는 다음 push 시 재설정되거나 현재 값 유지. count가 0이 되므로 문제 없음.
	count--;			// 원소 개수 감소
	return val;
}


// 4: 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다
int pop_back() {
	if (count == 0) {
		return -1;
	}
	int val = deque[rear_idx];		// 맨 뒤의 원소 가져오기
	if (count != 1) {
		rear_idx = (rear_idx - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	}
	// 만약 원소가 하나였다면, rear_idx는 다음 push시 재설정되거나 현재 값 유지. count가 0이 되므로 문제 없음
	count--;		// 원소 개수 감소
	return val;
}

// 5. 덱에 들어있는 정수의 개수를 출력한다.
int size() {
	return count;
}

// 6. 덱이 비어있으면 1, 아니면 0을 출력한다
int empty() {
	if (count == 0) {
		return 1;		// 비어있으면 1 반환
	}
	return 0;		// 비어있지 않으면 0 반환
}

// 7. 덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
int front() {
	if (count == 0) {
		return -1;
	}
	return deque[front_idx];		// 맨 앞의 원소 반환(제거하지 않음)
}

// 8. 덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.
int back() {
	if (count == 0) {
		return -1;
	}
	return deque[rear_idx];		// 맨 뒤의 원소 반환(제거하지 않음)
}

int main() {
	int n;		//명령의 수
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int command_type;
		scanf("%d", &command_type);			// 명령 종류를 입력받음

		switch (command_type) {
			case 1: {
				int x;
				scanf("%d", &x);
				push_front(x);
				break;
			}
			case 2: {
				int x;
				scanf("%d", &x);
				push_back(x);
				break;
			}
			case 3: {
				printf("%d\n", pop_front());
				break;
			}
			case 4: {
				printf("%d\n", pop_back());
				break;
			}
			case 5: {
				printf("%d\n", size());
				break;
			}
			case 6: {
				printf("%d\n", empty());
				break;
			}
			case 7: {
				printf("%d\n", front());
				break;
			}
			case 8: {
				printf("%d\n", back());
				break;
			}
			default:
				// 문제 조건상 주어지지 않는 명령
				break;

		}
	}
	return 0;	//프로그램 정상 종료
}