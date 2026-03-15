#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long n) {
    long long answer = -1;
    for (long long x = 0; x <= n; x++) {
        if (x * x == n)
            return ((x+1)*(x+1));
        else if (x * x > n)
            return -1;
    }
    return answer;
}