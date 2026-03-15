from collections import defaultdict
from pprint import pprint

def solution(n, results):
    wmap = defaultdict(set)
    lmap = defaultdict(set)
    
    for w, l in results:
        wmap[w].add(l)
        lmap[l].add(w)

    answer = 0
    for i in range(1, n+1) :
        visit = [False] * (n+1)
        stack = [i]
        while stack : # 이기는 선수들 탐색
            pop = stack.pop()
            for nxt in wmap[pop] :
                if visit[nxt] == True : continue
                visit[nxt] = True
                stack.append(nxt)
        num_win = sum(visit)

        visit = [False] * (n+1)
        stack = [i]
        while stack : # 지는 선수들 탐색
            pop = stack.pop()
            for nxt in lmap[pop] :
                if visit[nxt] == True : continue
                visit[nxt] = True
                stack.append(nxt)            
        num_lose = sum(visit)
        
        if num_win + num_lose == n-1 : 
            answer += 1

    return answer