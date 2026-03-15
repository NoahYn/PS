#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    long long temp = n;
    long long len = 1;
    while (temp / 10) {
        temp /= 10;
        len++;
    }
    int* answer = (int*)malloc(sizeof(int) * len + 1);
    for (int i = 0; i < len; i++) {
        answer[i] = n % 10;
        n /= 10;
    }
    
    return answer;
}