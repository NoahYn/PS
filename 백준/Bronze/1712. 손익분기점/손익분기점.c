#include<stdio.h>

int main (void)
{
    long A, B, C, X;
    scanf("%ld %ld %ld", &A, &B, &C);
    if (B >= C)
    {
        printf("-1");
        return 0;
    }
    X = A/(C-B)+1;
    printf("%d", X);
    return 0;
}