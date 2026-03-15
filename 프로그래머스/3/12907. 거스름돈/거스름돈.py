def solution(n, money):
    dp = [0] * (n+1)
    dp[0] = 1
    money.sort()
    for m in money :
        for i in range(1, n+1):
            if m > i : continue
            dp[i] = (dp[i] + dp[i-m]) % 1000000007
    return dp[n]