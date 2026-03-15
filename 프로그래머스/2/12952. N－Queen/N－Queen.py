def solution(n):
    vertical = [0 for _ in range(n)]
    horizontal = [0 for _ in range(n)]
    diagonal_up = [0 for _ in range(2*n-1)]
    diagonal_dn = [0 for _ in range(2*n-1)]
        
    def check(x, y) :
        return (horizontal[y] == 0 and 
                vertical[x] == 0 and 
                diagonal_up[x+y] == 0 and 
                diagonal_dn[n-1+x-y] == 0)
    
    def put(x, y, val) :
        vertical[x] = val
        horizontal[y] = val
        diagonal_up[x+y] = val
        diagonal_dn[n-1+x-y] = val

    answer = [0]
    def dfs(i, j, k) :
        if k == n : 
            answer[0] += 1
            dfs(0, j+1, 0)
        if i >= n or j >= n : return False
    
        if check(i, j) :
            put(i, j, 1)
            dfs(i+1, 0, k+1) 
            put(i, j, 0)
        dfs(i, j+1, k)  
        
    dfs(0, 0, 0)
    return answer[0]

