def solution(sticker):
    n = len(sticker)
    if n <= 3 : return max(sticker)
    dp = [0] * n
    
    # case 1. 첫 번째 스티커를 뜯는 경우(마지막, 두번째 제외)
    dp[0] = dp[1] = sticker[0]
    for i in range(2, n-1) :
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i])
        
    case1 = max(dp[n-1], dp[n-2])
    
    dp[0] = 0
    dp[1] = sticker[1]
    
    for i in range(2, n) :
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i])
    case2 = max(dp[n-1], dp[n-2])
        
    return max(case1, case2)
    # case 1 : 0번을 사용
    # 2 : 0번을 사용 x -> 1번 or -1 사용

    
    
    
    