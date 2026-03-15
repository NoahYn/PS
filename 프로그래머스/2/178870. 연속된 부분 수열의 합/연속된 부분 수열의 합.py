def solution(sequence, k):
    n = len(sequence)
    sums = [0] * (n+1)
    for i in range(n) :
        sums[i+1] = sums[i] + sequence[i]
    
    answer = []
    start = 0
    for end in range(1, n+1) :
        while sums[end] - sums[start] > k :
            start += 1
        
        if sums[end] - sums[start] == k : 
            answer.append([start, end-1])
    
    answer.sort(key=lambda x : (x[1]-x[0], x[0]))
    return answer[0]