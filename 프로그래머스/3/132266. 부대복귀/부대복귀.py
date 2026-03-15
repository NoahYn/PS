from collections import deque, defaultdict
from pprint import pprint

def solution(n, roads, sources, destination):
    vmap = defaultdict(list)
    dist = [-1] * (n+1)
    
    for v, w in roads :
        vmap[v].append(w)
        vmap[w].append(v)
    
    Q = deque([destination])
    dist[destination] = 0
    
    while Q :
        pop = Q.popleft()
        for nxt in vmap[pop] :
            if dist[nxt] > -1 : continue
            dist[nxt] = dist[pop] + 1
            Q.append(nxt)
  
    answer = []
    for s in sources :
        answer.append(dist[s])
    return answer