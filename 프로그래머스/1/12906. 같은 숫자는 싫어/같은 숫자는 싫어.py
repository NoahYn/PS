from collections import deque

def solution(arr):
    # arr of 0-9
    answer = deque()
    answer.append(arr[-1])
    
    while arr :
        pop = arr.pop()
        if answer and answer[0] != pop :
            answer.appendleft(pop)
    
    return list(answer)