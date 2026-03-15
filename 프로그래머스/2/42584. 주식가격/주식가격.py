def solution(prices):
    n = len(prices)
    answer = [n-i-1 for i in range(n)]
    stack = []
    
    for i in range(n):
        while stack and prices[stack[-1]] > prices[i] :
            j = stack.pop()
            answer[j] = i-j
        stack.append(i)
    
    return answer