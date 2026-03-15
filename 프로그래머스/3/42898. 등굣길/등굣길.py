from pprint import pprint

def solution(m, n, puddles):
    mod = 1000000007
    answer = 0
    DP = [[0] * n for _ in range(m)]
    
    for p1, p2 in puddles : 
        print(p1, p2)
        DP[p1-1][p2-1] = -1
    
    DP[0][0] = 1
    for i in range(m) :
        for j in range(n) :
            if DP[i][j] == -1 : continue
            if i > 0 and DP[i-1][j] > -1: 
                DP[i][j] += DP[i-1][j]
            if j > 0 and DP[i][j-1] > -1 : 
                DP[i][j] += DP[i][j-1]
            DP[i][j] %= mod
    
    return DP[m-1][n-1]
    
    return answer