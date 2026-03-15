from collections import defaultdict
### DFS 함수에 list를 전달하지 말고, list의 인자를 전달한 뒤 스코프 밖의 리스트에 추가하는 방식으로 구현해야 함

def solution(tickets):
    from_to = defaultdict(list)
    
    for f, t in tickets : 
        from_to[f].append(t)
    
    for key in from_to :
        from_to[key].sort()

    num_tickets = len(tickets)
    path = ["ICN"]
    
    def dfs(curr, count) :
        if num_tickets == count : 
            return path[:] # base condition

        for i in range(len(from_to[curr])) :
            dest = from_to[curr].pop(i)
            path.append(dest)

            result = dfs(dest, count + 1)
            if result : return result
            
            path.pop()
            from_to[curr].insert(i, dest)
        return None
    
    return dfs("ICN", 0)

