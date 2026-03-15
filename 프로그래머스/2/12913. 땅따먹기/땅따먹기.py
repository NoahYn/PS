from pprint import pprint

def solution(dp):  
    '''
    dp[n][4] 
    dp[i][0] += max([dp[i-1][1], dp[i-1][2], dp[i-1][3]]) 
    
    '''
    n = len(dp)
    for i in range(1, n) :
        dp[i][0] += max([dp[i-1][1], dp[i-1][2], dp[i-1][3]])
        dp[i][1] += max([dp[i-1][0], dp[i-1][2], dp[i-1][3]])
        dp[i][2] += max([dp[i-1][0], dp[i-1][1], dp[i-1][3]])
        dp[i][3] += max([dp[i-1][0], dp[i-1][1], dp[i-1][2]])
        
    return max(dp[n-1])
