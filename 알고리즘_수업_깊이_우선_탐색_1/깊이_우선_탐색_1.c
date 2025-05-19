/*
이 문제는 주어진 무방향 그래프에서 시작 정점 R로부터 깊이 우선 탐색(DFS)을 수행할 때
각 노드의 방문 순서를 출력하는 것입니다.
중요한 조건은 인접 정점을 방문할 때 정점 번호의 오름차순으로 방문해야 한다는 것입니다.
'

*/


#include <stdio.h>
#include <stdlib.h> // qsort, malloc, calloc, free 함수 사용
#include <string.h> // memset 함수 사용 (필요시)

#define MAX_N 100001 // 최대 정점 수 + 1
#define MAX_M 200001 // 최대 간선 수

// 인접 리스트를 위한 구조체 또는 변수들
int **adj; // 각 정점의 인접 정점들을 저장할 2차원 배열 (동적 할당)
int *degree; // 각 정점의 차수 (연결된 간선의 수)
int *visited_order; // 각 정점의 방문 순서 (0이면 미방문)
int order_counter; // 방문 순서를 기록하기 위한 카운터

// qsort를 위한 비교 함수 (오름차순 정렬)
int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 깊이 우선 탐색 함수
void dfs(int current_node) {
    visited_order[current_node] = order_counter++; // 현재 노드 방문 처리 및 순서 기록

    // 현재 노드에 인접한 노드들을 (오름차순으로 정렬된 순서대로) 방문
    for (int i = 0; i < degree[current_node]; i++) {
        int next_node = adj[current_node][i];
        if (visited_order[next_node] == 0) { // 아직 방문하지 않은 인접 노드라면
            dfs(next_node); // 재귀 호출
        }
    }
}

int main() {
    int N, M, R; // 정점의 수, 간선의 수, 시작 정점
    scanf("%d %d %d", &N, &M, &R);

    // 1. 차수 계산을 위한 degree 배열 초기화 (calloc은 0으로 초기화)
    degree = (int*)calloc(N + 1, sizeof(int));
    if (degree == NULL) return 1; // 메모리 할당 실패 처리

    // 간선 정보를 임시로 저장할 배열 (u, v 쌍)
    // 실제로는 간선 정보를 두 번 읽거나, 한 번 읽고 저장했다가 사용하는 방식이 있음
    // 여기서는 차수 먼저 계산 후, 다시 입력받는 것처럼 처리 (또는 파일에서 읽는다면 fseek 등)
    // 좀 더 효율적인 방법은 간선 정보를 저장해두는 것입니다.
    // 여기서는 간선 정보를 저장할 구조체 배열을 만듭니다.
    typedef struct { int u, v; } Edge;
    Edge *edges = (Edge*)malloc(M * sizeof(Edge));
    if (edges == NULL) {
        free(degree);
        return 1;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[i].u = u;
        edges[i].v = v;
        degree[u]++;
        degree[v]++;
    }

    // 2. 인접 리스트 메모리 할당
    adj = (int**)malloc((N + 1) * sizeof(int*));
    if (adj == NULL) {
        free(degree);
        free(edges);
        return 1;
    }
    for (int i = 1; i <= N; i++) {
        if (degree[i] > 0) { // 차수가 0이면 인접 리스트 할당 불필요
            adj[i] = (int*)malloc(degree[i] * sizeof(int));
            if (adj[i] == NULL) { /* 에러 처리: 이미 할당된 메모리 해제 */ return 1; }
        } else {
            adj[i] = NULL; // 명시적으로 NULL로 설정
        }
    }

    // 3. 인접 리스트 채우기
    // 각 인접 리스트에 현재 몇 개의 정점을 채웠는지 추적하기 위한 임시 배열
    int *current_adj_count = (int*)calloc(N + 1, sizeof(int));
    if (current_adj_count == NULL) { /* 에러 처리 */ return 1; }

    for (int i = 0; i < M; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        // u의 인접 리스트에 v 추가
        if (degree[u] > 0) {
             adj[u][current_adj_count[u]++] = v;
        }
        // v의 인접 리스트에 u 추가
        if (degree[v] > 0) {
            adj[v][current_adj_count[v]++] = u;
        }
    }
    free(edges); // 간선 임시 저장 배열 해제
    free(current_adj_count); // 임시 카운트 배열 해제

    // 4. 각 인접 리스트 오름차순 정렬
    for (int i = 1; i <= N; i++) {
        if (degree[i] > 0) { // 차수가 0보다 큰 경우에만 정렬
            qsort(adj[i], degree[i], sizeof(int), compare_int);
        }
    }

    // 방문 순서 배열 초기화 (calloc은 0으로 초기화)
    visited_order = (int*)calloc(N + 1, sizeof(int));
    if (visited_order == NULL) { /* 에러 처리 */ return 1;}

    order_counter = 1; // 방문 순서 카운터 1로 시작

    // DFS 시작
    dfs(R);

    // 결과 출력
    for (int i = 1; i <= N; i++) {
        printf("%d\n", visited_order[i]);
    }

    // 메모리 해제 (동적 할당된 메모리)
    for (int i = 1; i <= N; i++) {
        if (adj[i] != NULL) {
            free(adj[i]);
        }
    }
    free(adj);
    free(degree);
    free(visited_order);

    return 0;
}
