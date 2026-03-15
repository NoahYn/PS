from collections import deque, defaultdict

def solution(rectangle, characterX, characterY, itemX, itemY):
    maps = [[-1] * 104 for _ in range(105)] 

    for i in range(len(rectangle)) :               
        rectangle[i] = list(map(lambda x : x*2, rectangle[i]))
    characterX *= 2
    characterY *= 2
    itemX *= 2                   
    itemY *= 2                                    
                   
    # check outline
    for x1, y1, x2, y2 in rectangle :
        for x in range(x1, x2+1):
            maps[x][y1] = 0
            maps[x][y2] = 0

        for y in range(y1, y2+1):
            maps[x1][y] = 0
            maps[x2][y] = 0

    # check inner space 
    for x1, y1, x2, y2 in rectangle :
        for x in range(x1+1, x2) : 
            for y in range(y1+1, y2) :
                maps[x][y] = -1
    
    Q = deque()
    Q.append((characterX, characterY)) 
    maps[characterX][characterY] = 1
    
    while Q:
        x, y = Q.popleft()
        for dx, dy in [[0, 1], [0, -1], [1, 0], [-1, 0]] :
            nx = x + dx
            ny = y + dy
            if nx < 2 or ny < 2 or nx > 100 or ny > 100 : continue # OOB
            if maps[nx][ny] != 0 : continue # not path or already calculated

            maps[nx][ny] = maps[x][y] + 1
            Q.append((nx, ny))
    
    return maps[itemX][itemY]//2 
    
    