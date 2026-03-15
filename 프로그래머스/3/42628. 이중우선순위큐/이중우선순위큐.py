import heapq

def solution(operations):
    # 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return 
    Q = []
    for o in operations :
        command, data = o.split()
        if command == "I" :
            heapq.heappush(Q, int(data))
        elif command == "D" and Q :
            if data == "1" :
                Q.remove(max(Q))
            elif data == "-1" :
                heapq.heappop(Q)            
    return [0,0] if not Q else [max(Q), Q[0]]
            
    
    answer = []
    return answer