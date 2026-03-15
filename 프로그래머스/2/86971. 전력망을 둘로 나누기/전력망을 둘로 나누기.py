from collections import defaultdict

def solution(n, wires):
    neighbor_map = defaultdict(list)
    
    for v1, v2 in wires :
        neighbor_map[v1].append(v2)
        neighbor_map[v2].append(v1)
    
    answer = n
    for not_use in wires : # not_use[0] < not_use[1]
        visited = [False] * (n+1)
        visited[1] = True
        stack = [1]
        while stack : 
            curr = stack.pop()
            for to_visit in neighbor_map[curr] :
                if not visited[to_visit] :
                    if (curr == not_use[0] and to_visit == not_use[1]) or (curr == not_use[1] and to_visit == not_use[0]) :
                        continue
                    visited[to_visit] = True
                    stack.append(to_visit)
        
        candidate = abs(n - 2*sum(visited))
        answer = min(answer, candidate)
    
    return answer


'''
    len_wires = n-1
    edge_dict = defaultdict(set)
    
    for wire in wires :
        edge_dict[wire[0]].add(wire[1])
        edge_dict[wire[1]].add(wire[0])
        
    answer = n
    for delete in wires:
        disconnected = deepcopy(edge_dict)
        disconnected[delete[0]].remove(delete[1])
        disconnected[delete[1]].remove(delete[0])
        
        is_used = [False] * (n+1)
        stack = [1]
        is_used[1] = False

        while stack:
            pop = stack.pop()
            if not is_used[pop] :
                is_used[pop] = True
                stack.extend(disconnected[pop])
        
        num_connected = sum(is_used)
        candidate = abs(n - 2*num_connected)
        answer = min(candidate, answer)
'''