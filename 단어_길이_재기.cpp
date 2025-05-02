#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char word[101];	// 단어는 최대 100자이므로 널문자 포함해 101칸 배열 선언

	scanf("%s", word);	//문자열 입력 받기

	int length = strlen(word);	// 입력받은 문자열의 길이를 계산

	printf("%d\n", length);	//길이 출력

	return 0;	//프로그램 종류
}