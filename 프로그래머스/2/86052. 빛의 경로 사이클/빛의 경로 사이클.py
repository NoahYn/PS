from pprint import pprint
import sys
sys.setrecursionlimit(1000000)

def solution(grid):
    n = len(grid)
    m = len(grid[0])
    
    visit = [[[False] * 4 for _ in range(m)] for _ in range(n)]
    # n, m, direction(0상, 90우, 180하, 270좌)
    
    def circuit(i, j, d, path) :
        if visit[i][j][d] : return path[0]
        visit[i][j][d] = True
        path[0] += 1
        if grid[i][j] == 'L' :
            d = (d-1)%4
        elif grid[i][j] == 'R' :
            d = (d+1)%4
        
        if d == 0: # up
            i = (i-1)%n
        elif d == 1: # right
            j = (j+1)%m
        elif d == 2: # down
            i = (i+1)%n
        elif d == 3: # left
            j = (j-1)%m

        circuit(i, j, d, path)
    
    answer = []
    for i in range(n) :
        for j in range(m) :
            for d in range(4) :
                if visit[i][j][d] : continue
                path = [0]
                circuit(i, j, d, path)
                answer.append(path[0])
    
    if answer : return sorted(answer)   