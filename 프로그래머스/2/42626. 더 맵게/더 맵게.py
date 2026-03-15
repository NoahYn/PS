import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    
    answer = 0
    while(scoville[0] < K) :
        if len(scoville) < 2 : 
            return -1
        pop = heapq.heappop(scoville)
        pop2 = heapq.heappop(scoville)
        heapq.heappush(scoville, pop+pop2*2)
        answer += 1
    
    return answer