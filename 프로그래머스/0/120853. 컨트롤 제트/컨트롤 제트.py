from collections import deque

def solution(s):
    answer = 0

    values = s.split()
    nums = deque() 
    for v in values :
        if v == 'Z' :
            nums.pop()
        else :
            nums.append(int(v))
    answer = sum(nums)
        
    return answer