# 가장 큰 뭉치가 아니라 모든 index(최대20)에서 유턴해보면 더 간단

from collections import defaultdict

def solution(name):  
    size = len(name)
    total_cost = 0
    
    def cost_change(c: chr) : # cost to change from "A" to any character
        diff = abs(ord("A") - ord(c))
        return min(diff, 26-diff)
    
    # cost to change all the character
    for i in range(size) :
        total_cost += cost_change(name[i])        
    
    min_move = size - 1
    for i in range(size) :
        next_i = i + 1
        while next_i < size and name[next_i] == "A":
            next_i += 1
        
        dist1 = i
        dist2 = size - next_i
        
        min_move = min(min_move,
                       dist1 + dist2 + min(dist1, dist2))
        
    return total_cost + min_move
    
    
    
    
    
    
    
    # to find biggest chunk of A
    to_visit = [i for i in range(size) if name[i] == "A"]
    visited = [False] * size
    
    if not to_visit :
        return total_cost + size -1
    
    len_start = defaultdict(list)
    max_len = 0
    start = -1
    while not all(visited) and to_visit :
        visit = to_visit.pop()
        if visited[visit]:
            continue
        visited[visit] = True
        stack = [visit]
        length = 1
        
        while stack :
            pop = stack.pop()
            left = (pop+size-1)%size
            right = (pop+1)%size
            if name[left] == "A" and not visited[left] :
                visit = left
                visited[left] = True
                stack.append(left)
                length += 1
            if name[right] == "A" and not visited[right]:
                visited[right] = True
                stack.append(right)
                length += 1
        if max_len <= length :
            max_len = length
            start = visit
            len_start[max_len].append(start)
    
    if max_len == size : return 0

    min_cost = 1000
    for start in len_start[max_len] :
        end = (start + max_len -1)%size
        print(start, end)
        dist1 = start-1 if start != 0 else 0
        dist2 = size-end-1 if end != size else 0
        if start > end :
            min_cost = min(dist1, dist2, min_cost)
        print(size-1)
        print(dist1*2 + dist2)
        print(dist1 + dist2*2)
        min_cost = min(size-1, # cost to move through one direction
                    dist1*2 + dist2, # cost to go to start of A chunk, and u-turn
                    dist1 + dist2*2, # cost to go to end of A chunk, and u-turn
                    min_cost)
    
    return total_cost + min_cost
    
    
    
    