from pprint import pprint
from collections import defaultdict
from itertools import combinations
from math import comb

def solution(n, q, ans):
    domain = [i for i in range(1, n+1)]
    candidates = combinations(domain, 5)
    
    answer = 0
    i = 0
    for cand in candidates :
        isanswer = 1
        for nums, a in zip(q, ans) :
            cnt = sum([1 for num in nums if num in cand])
            if cnt != a :
                isanswer = 0
                break
        answer += isanswer
    
    return answer