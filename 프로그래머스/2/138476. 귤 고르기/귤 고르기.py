from collections import Counter

def solution(k, tangerine):
    C = Counter(tangerine)

    answer = 0
    for elm, cnt in C.most_common() : 
        k -= cnt
        answer += 1
        if k <= 0 :
            break

    return answer