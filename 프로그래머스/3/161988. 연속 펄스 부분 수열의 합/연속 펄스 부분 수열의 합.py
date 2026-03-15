import sys

# 누적합에서는 첫번째 원소만 사용하는 경우를 위해 s[0] = 0 필요 -> e1 = s[1]-s[0]이 가능함!!
# abs(max - min) 

def solution(sequence):
    n = len(sequence)
    s = [0] * (n+1)
    for i in range(n) :
        if i % 2 == 0 :
            s[i] = s[i-1] - sequence[i]
        else :
            s[i] = s[i-1] + sequence[i]
    
    answer = abs(max(s) - min(s))

    return answer
