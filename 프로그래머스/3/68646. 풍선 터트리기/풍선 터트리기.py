import sys

def solution(a):
    n = len(a)
    mn = sys.maxsize
    s = set()
    for b in a:
        if mn > b : 
            s.add(b)
            mn = b
    a.reverse()
    
    mn = sys.maxsize
    for b in a:
        if mn > b : 
            s.add(b)
            mn = b
    
    return len(s)