from collections import deque

def solution(n, stations, w):
    starts = deque([1])
    ends = deque([])
    for s in stations :
        starts.append(s+w+1)
        ends.append(s-w-1)
    ends.append(n)
    
    size = len(starts)
    answer = 0
    cover = w*2 +1
    from math import ceil
    for i in range(size) :
        s, e = starts[i], ends[i]
        blocks = e - s + 1
        if blocks > 0:
            needed = ceil(blocks/cover) 
            answer += needed
    return answer
'''
    # N이 억이면 O(N)도 x -> 비트마스킹 or 수학
    comm = [True] + [False for _ in range(n)]
    for s in stations :
        comm[s] = True
        for i in range(1, w+1) :
            if s-i >= 0 : 
                comm[s-i] = True
            if s+i < n+1 :
                comm[s+i] = True

    total = sum(comm) -1
    left = 1
    right = n
    answer = 0
    while total < n :
        if comm[left] == False :
            answer += 1
            for i in range(left, left+2*w+1) :
                if comm[i] == False :
                    comm[i] = True
                    total += 1
            left += 2*w+1
        else :
            left += 1
        if comm[right] == False :
            answer += 1
            for i in range(right, right-2*w-1, -1) :
                if comm[i] == False:
                    comm[i] = True
                    total += 1
            right -= (2*w+1)
        else :
            right -= 1
    
    return answer
'''