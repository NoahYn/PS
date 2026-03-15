def solution(n):
    if n == 1 : return 1
    cnt = 0
    while n > 1 :
        while n % 2 == 0 :
            n //= 2
        n -= 1
        cnt += 1
    return cnt
