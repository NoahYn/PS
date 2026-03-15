from collections import defaultdict, deque
from pprint import pprint
import heapq

def solution(gems):
    # deque slinding window
    # check front and encoming 
    # popleft if front == encoming
    # memo latest each element and use it for popping
    
    gem_set = set()
    gem_map = defaultdict(int)
    
    start = 0
    end = -1
    answer = []
    l = 0
    
    for i, g in enumerate(gems) :
        gem_set.add(g)
        if l != len(gem_set) :
            answer.clear()
            l = len(gem_set)
        
        if gem_map[g] == 0 or gems[start] == g:
            while end < i: # end~i 범위의 보석 추가
                end += 1
                gem_map[gems[end]] += 1

        while gem_map[gems[start]] > 1 :
            gem_map[gems[start]] -= 1
            start += 1

        heapq.heappush(answer, [end-start, start+1, end+1])
                
    start, end = answer[0][1:]
    return [start, end]