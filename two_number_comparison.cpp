//두 수 비교하기
//1330번
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b); //주소를 입력 받는다.

	if (a > b) {			//if문을 사용해서 비교식을 작성한다
		printf(">");		
	}
	else if (a < b) {		// 또는 else if를 사용하여 조건식을 작성
		printf("<");
	}
	else {					// 위의 모든 조건이 아니면 출력
		printf("==");
	}
	return 0;
}