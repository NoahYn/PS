# should be less than o(n)
# binary search

def solution(stones, k):
    size = len(stones)
    
    def possible(n):
        jump = 0
        for i in range(size) :
            if stones[i] <= n:
                jump += 1
                if jump >= k : 
                    return False
            else :
                jump = 0
        return True

    start, end = 1, max(stones)
    
    while start < end :
        mid = (start + end) // 2 
        if possible(mid) :
            start = mid + 1
        else :
            end = mid
    return start
