from collections import deque

def solution(priorities, location):
    cnt = 0
    priorities = deque(priorities)
    max_p = max(priorities)
    
    while location >= 0:
        pop = priorities.popleft()
        if not priorities : 
            cnt += 1
            break
        location -= 1
        if pop == max_p :
            max_p = max(priorities)
            cnt += 1
        else :
            priorities.append(pop)
            if location == -1 : location = len(priorities)-1
    return cnt
    
    
 