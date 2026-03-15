from collections import defaultdict, deque


def solution(n, edge):
    edge_map = defaultdict(list)
    dist = [0 for _ in range(n+1)]
    
    for v1, v2 in edge :
        edge_map[v1].append(v2)
        edge_map[v2].append(v1)

    Q = deque([1])
    dist[1] = 1
    mx_node = 0
    cnt = 1
    while Q :
        front = Q.popleft()
        for v in edge_map[front] :
            if dist[v] != 0 : 
                continue
            dist[v] = dist[front] + 1
            if dist[v] > mx_node :
                mx_node = dist[v]
                cnt = 1
            elif dist[v] == mx_node : 
                cnt += 1
            Q.append(v)
    
    return cnt
    