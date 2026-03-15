from collections import deque

def solution(maps):
    # 가능 시 최소 이동횟수, else -1
    # maps is nxm arr, players only move through square has 1 
    
    dx = [0, -1, 0, 1]
    dy = [1, 0, -1, 0]    
    n = len(maps)
    m = len(maps[0])
    
    queue = deque()
    queue.append((0, 0))
    
    while queue : 
        x, y = queue.popleft()
        for direction in range(4) :
            nx = x + dx[direction]
            ny = y + dy[direction]
            if nx < 0 or ny < 0 or nx >= n or ny >= m : continue # out of map
            if not maps[nx][ny] : continue # is not path(wall)
            if maps[nx][ny] > 1 : continue # already calculated
            maps[nx][ny] = maps[x][y] + 1
            
            queue.append((nx, ny))

            
    return maps[n-1][m-1] if maps[n-1][m-1] > 1 else -1
    
