from collections import defaultdict
from pprint import pprint

def solution(n, w, num):
    nmap = defaultdict(list) 
    target = -1
    
    for i in range(n) :
        rank = i // w
        if rank % 2 == 0 :
            nmap[i % w].append(i+1)
            if i+1 == num :
                target = i % w
        else :
            nmap[w-1- (i%w)].append(i+1)
            if i+1 == num :
                target = w-1-(i%w)

    answer = 0 
    while nmap[target] :
        answer += 1
        if num == nmap[target].pop() :
            break
    
    return answer