def solution(elements):
    S = set()
    for e in elements : 
        S.add(e)
    
    n = len(elements)
    total = sum(elements)
    for i in range(1,n) :
        for j in range(n) :
            temp = 0
            if j + i >= n :
                temp = (total - sum(elements[(j+i)%n:j]))
            else : 
                temp = (sum(elements[j:j+i]))
            S.add(temp)
    S.add(total)
    return len(S)