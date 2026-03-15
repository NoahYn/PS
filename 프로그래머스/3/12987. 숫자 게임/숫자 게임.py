import heapq

def solution(A, B):
    heapq.heapify(A)
    heapq.heapify(B)
    
    points = 0
    while B :
        if B[0] <= A[0] : # no point
            heapq.heappop(B)
        else : # point
            points += 1
            heapq.heappop(B)
            heapq.heappop(A)

    return points
