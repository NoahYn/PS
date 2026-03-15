from collections import defaultdict
from pprint import pprint

def solution(enroll, referral, seller, amount):
    # simul
    refmap = defaultdict(str)
    profits = defaultdict(int)
    for e, r in zip(enroll, referral) :
        if r == "-" : 
            continue
        refmap[e] = r

    for s, a in zip(seller, amount) :
        profits[s] += 0.9 * 100 * a
        parent = refmap[s]
        residue = 0.1 * 100 * a
        while parent :
            if residue < 10 :
                profits[parent] += residue
                break
            else :
                profits[parent] += (residue - residue//10)
                residue = residue//10            
                parent = refmap[parent]
                                      
    answer = []
    for e in enroll :
        answer.append(int(profits[e]))
    return answer