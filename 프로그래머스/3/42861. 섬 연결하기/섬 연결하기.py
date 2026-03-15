from collections import defaultdict, deque
from pprint import pprint

def find_parent(parent, a) :
    if parent[a] != a :
        parent[a] = find_parent(parent, parent[a])
    return parent[a]

## set shortcut
'''
def find_parent(parent, a) :
    if parent[a] == a : 
        return a
    return find_parent(parent, parent[a])
'''

def union_parent(parent, a, b) :
    if a > b : 
        parent[a] = b
    else : 
        parent[b] = a
    

def solution(n, costs):
    parent = [i for i in range(n)]
    
    answer = 0
    costs.sort(key = lambda x : x[2])
    num_edge = 0
    for v1, v2, c in costs :
        root1 = find_parent(parent, v1)
        root2 = find_parent(parent, v2)
        if root1 != root2 :
            union_parent(parent, root1, root2)
            answer += c
            num_edge += 1
            if num_edge >= n-1 :
                break
        
    return answer