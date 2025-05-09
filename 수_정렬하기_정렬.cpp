/*
문제 분석
- N개의 정수가 주어지며, 이를 오름차순으로 정렬해야 합니다
- 정렬할 숫자는 중복되지 않으며, 1000 이하의 정수 입니다
- 정렬된 숫자를 한 줄에 하나씩 출력해야 합니다


알고리즘 설명
1. 입력받기: 첫 번재 줄에서 정수 N을 입력받습니다. 이 N은 정렬할 수의 개수를 나타냅니다.
2. 배열생성: 크기가 N인 정수 배열을 생성하여 N개의 숫자를 저장합니다.
3. 정렬: 오름차순으로 배열을 정렬합니다. 여기서는 qsort 함수를 사용하여 빠르게 정렬합니다.
4. 출력: 정렬된 배열을 하나씩 출력합니다.
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


// 비교 함수: qsort에서 사용할 비교 함수
// 양수를 반환하면 a가 b보다 큰 것이며, 이는 오름차순 정렬을 의미
int compare(const void* a, const void* b) {
	// 정수를 가리키는 포인터를 정수로 변환하여 값을 비교
	return (*(int*)a - *(int*)b);
}

int main() {
	int N;

	// 1. N 입력 받기
	scanf("%d", &N);

	// 2. 동적 메모리 할당
	int* numbers = (int*)malloc(N * sizeof(int));
	if (numbers == NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}

	// 3. N개의 정수 입력 받기
	for (int i = 0; i < N; i++) {
		scanf("%d", &numbers[i]);
	}

	// 4. wjdfuf: qsort 함수 사용
	// qsort(배열 시작 주소, 요소 개수, 각 요소 크기, 비교 함수)
	qsort(numbers, N, sizeof(int), compare);


	// 5. 정렬된 숫자 출력
	for (int i = 0; i < N; i++) {
		printf("%d\n", numbers[i]);
	}


	return 0;
}