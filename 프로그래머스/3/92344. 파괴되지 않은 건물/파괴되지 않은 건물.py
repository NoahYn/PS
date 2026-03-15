from pprint import pprint

def solution(board, skill):
    
    n = len(board)
    m = len(board[0])
    
    diff = [[0 for _ in range(m)] for _ in range(n)]
    
    for typ, r1, c1, r2, c2, degree in skill :
        if typ == 1 :
            degree *= -1
        diff[r1][c1] += degree
        
        if r2+1 < n :
            diff[r2+1][c1] -= degree
        if c2+1 < m : 
            diff[r1][c2+1] -= degree
        if r2+1 < n and c2+1 < m :   
            diff[r2+1][c2+1] += degree
    
    for i in range(n) :
        for j in range(1, m) :
            diff[i][j] += diff[i][j-1]
    
    for i in range(1, n) :
        for j in range(m) :
            diff[i][j] += diff[i-1][j]
    
    answer = 0
    for i in range(n) :
        for j in range(m) :
            answer += 1 if (diff[i][j] + board[i][j]) > 0 else 0 
    
    return answer
    
