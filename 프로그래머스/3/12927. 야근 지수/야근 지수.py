from collections import Counter

def solution(n, works):
    ct = Counter(works)
    mx = max(works) 
    for i in range(mx, 0, -1) :
        val = ct[i]
        if val < n :
            ct[i] = 0
            ct[i-1] += val
            n -= val
        else :
            ct[i] -= n
            ct[i-1] += n
            break
    answer =0
    for k, v in ct.items() :
        if v == 0 : continue
        answer += k**2 * v
    
    return answer