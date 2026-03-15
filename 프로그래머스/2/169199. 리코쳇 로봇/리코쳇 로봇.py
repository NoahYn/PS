from pprint import pprint
from collections import deque

def solution(board):
    n = len(board)
    m = len(board[0])
    
    dist = [[0 for _ in range(m)] for _ in range(n)]

    Q = deque()
    goal = 0
    for i in range(n) :
        for j in range(m) :
            if board[i][j] == 'R' :
                Q.append([i,j])
                dist[i][j] = 1
            elif board[i][j] == 'D' :
                dist[i][j] = -1
            elif board[i][j] == 'G' :
                goal = (i, j)
    
    while Q :
        x, y = Q.popleft()
        for dx, dy in [[0, 1], [0, -1], [1, 0], [-1, 0]] :
            nx, ny = x, y
            while nx + dx >= 0 and nx + dx < n and ny + dy >= 0 and ny + dy < m :
                if board[nx+dx][ny+dy] == 'D' :
                    break
                nx += dx
                ny += dy
            
            if dist[nx][ny] > 0 :
                continue
            dist[nx][ny] = dist[x][y] + 1
            Q.append([nx, ny])
    
    (x, y) = goal
    return dist[x][y] -1
