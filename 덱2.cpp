/*
�� ������ ������ �����ϴ� ��(Deque, Double-Ended Queue)�� �����ϰ�,
�־��� ����� ó���ϴ� ���α׷� �Դϴ�.
���� ���� ��(�հ� ��)���� ��� ������ ����(push)�� ����(pop)�� ������ �ڷᱸ��

*/


#include<stdio.h>

#define MAX_DEQUE_SIZE 100000000	// �������� N�� �ִ밪�� 1,000,000 �̹Ƿ� ���� �ִ� ũ�⵵ �̿� �°� ����

int deque[MAX_DEQUE_SIZE];			// ������ ������ �� �迭
int front_idx = 0;					// ���� ���� �� ������ �ε���
int rear_idx = 0;					// ���� ���� �� ������ �ε���
int count = 0;						// ���� ����ִ� ������ ����


// 1: ���� X�� ���� �տ� �ִ´�.
void push_front(int x) {
	if (count >= MAX_DEQUE_SIZE) {		// ���� �� á���� Ȯ��(�̷л�, ���� ���ǿ����� N�� ����)
		printf("Deque is full\n");
		return;
	}
	if (count == 0) {
		front_idx = 0;
		rear_idx = 0;
		deque[front_idx] = x;
	}
	else {
		front_idx = (front_idx - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;		//front�� ������ �̵�
		deque[front_idx] = x;
	}
	count++;		// ���� ���� ����
}

// 2. ���� X�� ���� �ڿ� �ִ´�.
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
		rear_idx = (rear_idx + 1) % MAX_DEQUE_SIZE;	//rear�� �ڷ� �̵�
		deque[rear_idx] = x;
	}
	count++;			// ���� ���� ����
}

// 3. ���� ������ �ִٸ� �� ���� ������ ���� ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
int pop_front() {
	if (count == 0) {
		return -1;
	}
	int val = deque[front_idx];		//�� ���� ���� ��������
	if (count != 1) {
		front_idx = (front_idx + 1) % MAX_DEQUE_SIZE;
	}���Ѵ�.
	// ���� ���Ұ� �ϳ����ٸ�, front_idx�� ���� push �� �缳���ǰų� ���� �� ����. count�� 0�� �ǹǷ� ���� ����.
	count--;			// ���� ���� ����
	return val;
}


// 4: ���� ������ �ִٸ� �� ���� ������ ���� ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�
int pop_back() {
	if (count == 0) {
		return -1;
	}
	int val = deque[rear_idx];		// �� ���� ���� ��������
	if (count != 1) {
		rear_idx = (rear_idx - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	}
	// ���� ���Ұ� �ϳ����ٸ�, rear_idx�� ���� push�� �缳���ǰų� ���� �� ����. count�� 0�� �ǹǷ� ���� ����
	count--;		// ���� ���� ����
	return val;
}

// 5. ���� ����ִ� ������ ������ ����Ѵ�.
int size() {
	return count;
}

// 6. ���� ��������� 1, �ƴϸ� 0�� ����Ѵ�
int empty() {
	if (count == 0) {
		return 1;		// ��������� 1 ��ȯ
	}
	return 0;		// ������� ������ 0 ��ȯ
}

// 7. ���� ������ �ִٸ� �� ���� ������ ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
int front() {
	if (count == 0) {
		return -1;
	}
	return deque[front_idx];		// �� ���� ���� ��ȯ(�������� ����)
}

// 8. ���� ������ �ִٸ� �� ���� ������ ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
int back() {
	if (count == 0) {
		return -1;
	}
	return deque[rear_idx];		// �� ���� ���� ��ȯ(�������� ����)
}

int main() {
	int n;		//����� ��
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int command_type;
		scanf("%d", &command_type);			// ��� ������ �Է¹���

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
				// ���� ���ǻ� �־����� �ʴ� ���
				break;

		}
	}
	return 0;	//���α׷� ���� ����
}