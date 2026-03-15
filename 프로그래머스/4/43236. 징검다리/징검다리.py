import heapq

def solution(distance, rocks, n):
    if len(rocks) == n : return distance
    
    def satisfy(x, rocks) :
        cnt = 0
        for i in range(1, len(rocks)):
            dis = rocks[i] - rocks[i-1]
            if dis < x and dis > 0 :
                rocks[i] = rocks[i-1]
                cnt += 1
                if cnt > n:
                    return False
        return True
    
    rocks.extend([0, distance])
    rocks.sort()

    lb = 1
    ub = 1
    while satisfy(ub, rocks[:]) : ub <<= 1

    while lb < ub : 
        mid = lb + (ub - lb)//2
        if satisfy(mid, rocks[:]) : lb = mid + 1
        else : ub = mid
    return lb-1
