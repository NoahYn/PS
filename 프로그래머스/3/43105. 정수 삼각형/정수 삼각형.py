def solution(tri):
    size = len(tri[-1])
    DP = tri[-1]
    
    for i in range(size-2, -1, -1) :
        dp = tri[i][:]
        for j in range(len(tri[i])) :
            if DP[j] > DP[j+1] :
                dp[j] += DP[j]
            else : 
                dp[j] += DP[j+1]
        DP = dp[:]
    
    return DP[0]