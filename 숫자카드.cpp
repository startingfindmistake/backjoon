/*
이 문제는 상근이가 가진 N개의 숫자 카드 중에, 주어진 M개의 숫자가 각각 존재하는지 확인 하는 문제
N과 M의 크기가 최대 500,000 이므로, 효율적인 탐색 방법이 필요합니다

- 단순히 M개의 각 숫자에 대해 N개의 카드를 순차적을 ㅗ비교하면 시간 복잡도가 O(n*m)이 되어 시간 초과 발생
(최악의 경우 500,000 * 500,000 = 2.5 * 10^11연산)
- 따라서 상근이가 가진 카드를 미리 정렬한 후, 
각 M개의 숫자에 대해 이진탐색(binary search)을 사용하면 훨씬 빠르게 존재 여부를 확인가능



알고리즘 단계
1. 입력(상근이의 카드):
- 첫 번째 줄에서 상근이가 가진 숫자 카드의 개수 N을 입력받습니다
- 두 번째 줄에서 N개의 정수를 입력받아 배열 (sangGeunCards)에 저장합니다

2. 상근이의 카드 정렬
- sangGeunCards 배열을 오름차순으로 정렬합니다
C언어에서 stdlib.h 헤더 파일의 qsort 함수를 사용할 수 있습니다.
정렬 시간 복잡도는 일반저긍로 O(N log N) 입니다

3. 입력(확인할 카드):
- 세 번째 줄에서 확인할 숫자의 개수 M을 입력받습니다
- 네 번째 줄에서 M개의 정수를 입력받습니다. 이 숫자들은 배열에 저장할 수도 있지만,
하나씩 입력받아 바로 처리하는 것이 메모리 측면에서 더 효율적일 수 있습니다

4. 탐색 및 출력(M개의 각 카드에 대해)
- M개의 각 숫자에 대해 다음을 반복합니다
	- 확인할 숫자 targetNum을 하나 읽습니다
	- 정렬된 sangGeunCards 배열에서 targetNum을 이진탐색으로 찾습니다
		- 이진 탐색 과정
			1. 탐색 범위의 시작(low), 끝(high)인덱스를 설정합니다
			2. low <= high 인 동안 반복합니다
			3. 중간 인덱스 mid = (low + high) / 2를 계산합니다
			4. sangGeunCards[mid] 와 targetNum을 비교합니다
				- sangGeunCards[mid] == targetNum : 숫자를 찾았으므로 1을 출력하고 탐색을 종료 합니다
				- sangGeunCards[mid] < targetNum: targetNum은 중간값보다 크므로,
				오른쪽 부분 배열에서 탐색을 계속합니다(low = mid + 1)
				- sangGeunCards[mid] > targetNum : targetNum 은 중간값보다 작으므로,
				왼쪽 부분 배열에서 탐색을 계속합니다(high = mid - 1)
			5. 반복문이 끝날 때까지 targetNum을 찾지 못하면 해당 숫자는 상근이의 카드에 없는 것입니다
			0을 출력합닏

		- 각 결과를 출력할 때, 첫 번째 결과를 제외하고는 앞에 공백을 하나씩 추가하여 출력 형식에 맞춘다

시간 복잡도:

-상근이 카드 정렬: O(N log N)
-M개의 숫자에 대한 이진 탐색: M * O(log N) = O(M log N)
-총 시간 복잡도: O(N log N + M log N) = O((N+M) log N)
-N, M이 최대 500,000일 때, log₂(500,000)은 약 19입니다.
-(500,000 + 500,000) * 19 ≈ 1,000,000 * 19 = 1.9 * 10^7 이므로, 시간 제한 내에 충분히 통과할 수 있습니다.

*/


#include <stdio.h>
#include <stdlib.h> // qsort 함수 및 이진 탐색 함수(bsearch)를 위해 필요

// qsort 함수에 사용될 비교 함수 (오름차순 정렬)
int compare_integers(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
    // 또는 간단하게 return arg1 - arg2; (오버플로우 가능성 있으나, 이 문제 범위에서는 괜찮음)
    // return (*(int*)a - *(int*)b); // 더 간결한 표현
}

// 이진 탐색 함수 직접 구현
// arr: 정렬된 배열
// size: 배열의 크기
// target: 찾고자 하는 값
// 반환값: 찾으면 1, 못 찾으면 0
int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2; // 오버플로우 방지를 위해 (low + high) / 2 대신 사용

        if (arr[mid] == target) {
            return 1; // 찾았음
        }
        else if (arr[mid] < target) {
            low = mid + 1; // 오른쪽 부분 탐색
        }
        else {
            high = mid - 1; // 왼쪽 부분 탐색
        }
    }
    return 0; // 못 찾았음
}


int main() {
    int n; // 상근이가 가지고 있는 숫자 카드의 개수
    scanf("%d", &n);

    // 상근이의 숫자 카드를 저장할 배열 동적 할당
    int* sang_geun_cards = (int*)malloc(n * sizeof(int));
    if (sang_geun_cards == NULL) {
        // 메모리 할당 실패 처리 (문제에서는 보통 발생하지 않음)
        return 1;
    }

    // 상근이의 숫자 카드 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &sang_geun_cards[i]);
    }

    // 상근이의 숫자 카드를 오름차순으로 정렬 (이진 탐색의 전제 조건)
    qsort(sang_geun_cards, n, sizeof(int), compare_integers);

    int m; // 구해야 할 숫자의 개수
    scanf("%d", &m);

    int target_num; // 구해야 할 숫자
    // M개의 숫자에 대해 상근이가 가지고 있는지 확인
    for (int i = 0; i < m; i++) {
        scanf("%d", &target_num);

        // 이진 탐색을 사용하여 target_num이 sang_geun_cards 배열에 있는지 확인
        // 방법 1: 직접 구현한 이진 탐색 함수 사용
        int found = binary_search(sang_geun_cards, n, target_num);

        // 방법 2: C 표준 라이브러리의 bsearch 함수 사용
        // int *found_ptr = (int *)bsearch(&target_num, sang_geun_cards, n, sizeof(int), compare_integers);
        // int found = (found_ptr != NULL); // 포인터가 NULL이 아니면 찾은 것

        printf("%d", found);

        // 마지막 숫자가 아니면 공백 출력
        if (i < m - 1) {
            printf(" ");
        }
    }
    printf("\n"); // 모든 출력 후 줄 바꿈

    // 동적 할당된 메모리 해제
    free(sang_geun_cards);

    return 0; // 프로그램 정상 종료
}

/*
코드 설명:

#include <stdio.h>: 표준 입출력 함수 (scanf, printf)를 사용하기 위해 포함합니다.
#include <stdlib.h>: qsort (정렬 함수), bsearch (이진 탐색 함수, 여기서는 직접 구현한 것을 사용), malloc (동적 메모리 할당), free (메모리 해제) 함수를 사용하기 위해 포함합니다.
compare_integers 함수:
qsort 함수와 bsearch 함수는 정렬하거나 검색할 요소들을 비교하는 방법을 지정하는 함수를 필요로 합니다.
이 함수는 두 개의 const void * 타입의 포인터를 인자로 받아, 이 포인터들이 가리키는 정수 값을 비교합니다.
첫 번째 인자가 두 번째 인자보다 작으면 음수, 같으면 0, 크면 양수를 반환하여 오름차순 정렬을 수행합니다.
binary_search 함수 (직접 구현):
정렬된 배열 arr에서 target 값을 찾는 함수입니다.
low, high는 탐색 범위의 시작과 끝 인덱스를 나타냅니다.
mid = low + (high - low) / 2;는 (low + high)가 정수 범위를 넘어 오버플로우되는 것을 방지하기 위한 안전한 중간값 계산 방법입니다.
arr[mid]와 target을 비교하여 탐색 범위를 절반씩 줄여나갑니다.
값을 찾으면 1을, 찾지 못하면 0을 반환합니다.
main 함수:
N 입력 및 카드 저장: N을 입력받고, N개의 정수를 저장할 sang_geun_cards 배열을 malloc으로 동적 할당합니다. 이후 카드 번호를 입력받아 배열에 저장합니다.
정렬: qsort(sang_geun_cards, n, sizeof(int), compare_integers);를 호출하여 sang_geun_cards 배열을 오름차순으로 정렬합니다.
M 입력 및 탐색/출력 루프:
M을 입력받습니다.
for 루프를 M번 반복하면서, 각 target_num을 입력받습니다.
binary_search 함수를 호출하여 target_num이 sang_geun_cards에 있는지 확인합니다.
주석 처리된 부분은 C 표준 라이브러리 bsearch 함수를 사용하는 예시입니다. bsearch는 찾은 요소의 포인터를 반환하거나, 찾지 못하면 NULL을 반환합니다.
결과(1 또는 0)를 출력합니다.
if (i < m - 1) 조건을 통해 마지막 숫자가 아닐 경우에만 결과 뒤에 공백을 출력합니다.
메모리 해제: free(sang_geun_cards);를 호출하여 동적으로 할당했던 메모리를 해제합니다. (메모리 누수 방지)
return 0;으로 프로그램을 정상 종료합니다

*/