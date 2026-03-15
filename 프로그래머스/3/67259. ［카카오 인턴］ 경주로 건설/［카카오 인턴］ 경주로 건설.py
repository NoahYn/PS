from collections import deque

def solution(board):
    n = len(board)
    direc = [[0, 1], [-1, 0], [0, -1], [1, 0]]
    cost = [[[float('inf') for _ in range(n)] for _ in range(n)] for _ in range(4)]
    
    Q = deque()
    Q.append([0, 0, -1])
    cost[0][0][0] = 0
    cost[1][0][0] = 0
    cost[2][0][0] = 0
    cost[3][0][0] = 0

    while Q :
        x, y, direction = Q.popleft()
        for d, (dx, dy) in enumerate(direc) :
            nx, ny = x+dx, y+dy
            if nx < 0 or ny < 0 or nx >= n or ny >= n :
                continue
            if board[nx][ny] == 1 :
                continue
            if direction == -1 or direction == d:
                if cost[d][nx][ny] > cost[d][x][y] + 100 :
                    Q.append([nx, ny, d])
                    cost[d][nx][ny] = cost[d][x][y] + 100
            else :
                if cost[d][nx][ny] > cost[direction][x][y] + 600 :
                    Q.append([nx, ny, d])
                    cost[d][nx][ny] = cost[direction][x][y] + 600

    answer = min(cost[0][n-1][n-1], min(cost[1][n-1][n-1], min(cost[2][n-1][n-1], cost[3][n-1][n-1])))
    return answer