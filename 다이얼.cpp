#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	// 다이얼 숫자 2~9에 해당하는 알파벳 그룹을 문자열 배열로 선언
	//예 : dial[0]은 숫자 2번 키에 해당하는 문자들 "ABC"
    const char* dial[] = {
        "ABC",    // 2번 키 → 걸기 시간: 3초
        "DEF",    // 3번 키 → 4초
        "GHI",    // 4번 키 → 5초
        "JKL",    // 5번 키 → 6초
        "MNO",    // 6번 키 → 7초
        "PQRS",   // 7번 키 → 8초
        "TUV",    // 8번 키 → 9초
        "WXYZ"    // 9번 키 → 10초
    };

    char input[16]; // 입력 받을 문자열 (최대 15자 + 널 문자 포함해서 16칸)
    scanf("%s", input); //사용자로부터 문자열 입력

    int total = 0;  //총 소요 시간을 저장할 변수

    //입력 문자열을 한 글자씩 검사
    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i]; //현재 문자 저장


        // 다이얼 문자 그룹 배열을 순회하며 ch가 속한 그룹을 찾음
        for (int j = 0; j < 8; j++) {
            //strchr: 특정 문자(ch)가 문자열 (dial[j])안에 있는지 확인
            if (strchr(dial[j], ch)) {
                //찾았다면: 해당 번호를 누르는 데 걸리는 시간은 j + 3초
                //예: dial[0] -> 2qjs zl -> 3ch, dial[1] -> 3번 키 -> 4초...
                total += j + 3;
                break;  //해당 그룹을 찾았으니 반복 종료(불필요한 검사 방지)
            }
        }
    }

    //최 종 결과 출력
    printf("%d\n", total);

    return 0; //프로그램 종류
}