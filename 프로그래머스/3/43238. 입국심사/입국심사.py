
def solution(n, times):
    lb = 0
    ub = 1#min(times) * n
    def enough(x) :
        lines = 0
        for t in times :
            lines += x // t
            if lines >= n :
                return True
        return False    

    while not enough(ub) :
        ub <<= 1  
        
    while lb < ub : 
        mid = lb + (ub - lb)//2
        if enough(mid) : ub = mid
        else           : lb = mid + 1
    
    return lb
    
    '''
    array = []
    for x in times :
        array.extend([i * x for i in range(1, n-len(times)+1)])
    array.sort()

    return array[n-1]
    '''