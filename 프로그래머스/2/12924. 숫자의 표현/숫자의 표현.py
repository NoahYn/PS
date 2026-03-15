from collections import deque

def solution(n):
    if n < 3 : return 1
    
    total = 0
    start = 0
    answer = 0
    for end in range(1, n//2+2) :
        total += end
        while total > n :
            start += 1
            total -= start
        if total == n :
            answer += 1
    answer += 1    
    return answer
'''
def solution(n):
    if n < 3 :
        return 1

    dq = deque()
    total = 0
    answer = 0
    for i in range(1, n+1) :
        dq.append(i)
        total += i
        while dq and total > n :
            total -= dq.popleft()
        
        if total == n :
            answer += 1
    return answer
'''