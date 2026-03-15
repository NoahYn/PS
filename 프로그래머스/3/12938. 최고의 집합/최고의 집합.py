
def solution(n, s):
    if s < n :    
        return [-1]
    
    answer = []
    n2, s2 = n, s
    while n2 :
        temp = s//n2
        answer.append(temp)
        s -= temp        
        n2 -= 1

    answer.sort()
    return answer