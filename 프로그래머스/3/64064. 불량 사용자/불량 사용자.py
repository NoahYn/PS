from collections import defaultdict
from pprint import pprint

def solution(user_id, banned_id):
    cands = []
    
    n = len(banned_id)
    for b in banned_id :
        cand = []
        for u in user_id :
            if len(u) != len(b) :
                continue
            cand.append(u)
            for i in range(len(u)) :
                if b[i] == '*' or b[i] == u[i] :
                    continue
                else : 
                    cand.pop()
                    break
        cands.append(cand)
        
    umap = {}
    for i, u in enumerate(user_id) :
        umap[u] = i
    
    answer = set()
    visit = {u: False for u in user_id}
    
    def dfs(i, path) :
        if i == n :
            answer.add(str(sorted(path)[:]))
            return
        for c in cands[i] :
            if visit[c] == True : continue
            visit[c] = True
            path.append(umap[c])
            dfs(i+1, path)
            path.pop()
            visit[c] = False            
    
    dfs(0, [])
    return len(answer)
        
    