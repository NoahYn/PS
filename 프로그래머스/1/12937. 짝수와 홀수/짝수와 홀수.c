#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int num) {
    // 리턴할 값은 메모리를 동적 할당해주세요
    char *answer;
    if (num % 2 == 0) {
        answer = (char*)malloc(5);
        answer = "Even";
    }
    else {
        answer = (char*)malloc(4);
        answer = "Odd";
    }
    return answer;
}