from collections import defaultdict

def solution(n: int, lost: list, reserve: list) -> int:
    counts = [1] * (n + 2)
    counts[0] = counts[n+1] = -1

    
    for i in lost : 
        counts[i] -= 1
        
    for i in reserve :
        counts[i] += 1
    
    lost = [i for i, value in enumerate(counts) if value == 0]
    lost.sort()

    for i in lost :
        if counts[i-1] == 2:
            counts[i-1] -= 1
            counts[i] += 1
        elif counts[i+1] == 2:
            counts[i+1] -= 1
            counts[i] += 1
            
    return sum([1 for c in counts if c > 0])
