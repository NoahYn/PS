from pprint import pprint
from collections import defaultdict
import heapq

def solution(n, s, a, b, fares):
    # 지점 개수 n 3~200
    # s 출발, a도착, b도착
    
    faremap = defaultdict(list)
    for x, y, f in fares :
        faremap[x].append([f, y])
        faremap[y].append([f, x])
    
    dist_a = [float('inf')] * (n+1)        
    Q = [[0, a]] # a to a는 0
    dist_a[a] = 0
    while Q : 
        cfare, curr = heapq.heappop(Q) # fare, nxt
        for nfare, nxt in faremap[curr] :
            if dist_a[nxt] > cfare + nfare :
                dist_a[nxt] = cfare + nfare
                heapq.heappush(Q, [cfare+nfare, nxt])
           
    dist_b = [float('inf')] * (n+1)        
    Q = [[0, b]] # a to a는 0
    dist_b[b] = 0
    while Q : 
        cfare, curr = heapq.heappop(Q) # fare, nxt
        for nfare, nxt in faremap[curr] :
            if dist_b[nxt] > cfare + nfare :
                dist_b[nxt] = cfare + nfare
                heapq.heappush(Q, [cfare+nfare, nxt])

    dist_s = [float('inf')] * (n+1)        
    Q = [[0, s]] # a to a는 0
    dist_s[s] = 0
    while Q : 
        cfare, curr = heapq.heappop(Q) # fare, nxt
        for nfare, nxt in faremap[curr] :
            if dist_s[nxt] > cfare + nfare :
                dist_s[nxt] = cfare + nfare
                heapq.heappush(Q, [cfare+nfare, nxt])
    
    
    answer = dist_a[s] + dist_b[s]# 따로 A, B에 가는 방법으로 초기화
    for i in range(1, n+1) : # i까지 같이 타고 따로 가는 방법 확인
        if dist_a[i] == float('inf') or dist_b[i] == float('inf') : continue
        answer = min(answer, dist_s[i]+dist_a[i]+dist_b[i])
        
    
    
    return answer