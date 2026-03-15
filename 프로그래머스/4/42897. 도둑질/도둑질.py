def solution(money):
    dp1 = [0 for _ in range(len(money))]
    dp2 = [0 for _ in range(len(money))]
    
    dp1[0] = dp1[1] = money[0] # 첫번째 집 털고, 두번째 집과 마지막 집은 못 텀
    dp2[0] = 0 # 첫번째 집 안텀
    
    for i in range(2, len(money)-1) :
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i])
    
    for i in range(1, len(money)) :
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i])
        
    return max(dp1[-2], dp2[-1])