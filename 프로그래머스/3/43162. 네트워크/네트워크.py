def solution(n, computers):
    visit = [False] * n
    
    count = 0
    stack = []
    for i in range(n):
        if visit[i] : 
            continue

        visit[i] = True
        stack.append(i)
        
        while stack:
            node = stack.pop()
            connected = [j for j in range(n) if computers[node][j] == 1]
            for j in connected :
                if visit[j] :
                    continue
                visit[j] = True
                stack.append(j)
        count += 1
        
    return count