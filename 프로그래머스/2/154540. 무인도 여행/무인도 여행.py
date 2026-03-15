from collections import defaultdict

def solution(maps):
    n = len(maps)
    m = len(maps[0])
    k = 0 # arrea index
    area = [[0 for _ in range(m)] for _ in range(n)]
    
    for i in range(n) :
        for j in range(m) :
            if maps[i][j] == 'X' or area[i][j] > 0 : 
                continue
            stack = [[i,j]]
            k += 1
            area[i][j] = k
            
            while stack : 
                x, y = stack.pop()
                for dx, dy in [[0, 1], [0, -1], [1, 0], [-1, 0]] :
                    nx, ny = x + dx, y + dy
                    if nx < 0 or ny < 0 or nx >= n or ny >= m : continue
                    if maps[nx][ny] == 'X' or area[nx][ny] > 0 : continue
                    area[nx][ny] = k
                    stack.append([nx, ny])
    
    answer = defaultdict(int)
    for i in range(n) :
        for j in range(m) :
            if area[i][j] == 0 : continue
            k = area[i][j]
            answer[k] += int(maps[i][j])
            
    answer = list(answer.values())
    if not answer : return [-1]
    return sorted(answer)
