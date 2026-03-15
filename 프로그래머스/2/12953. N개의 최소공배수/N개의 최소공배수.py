from math import gcd

def solution(arr):
    def lcm(a, b) :
        return a*b//gcd(a, b)
    
    answer = 1
    for n in arr :
        answer = lcm(n, answer)
        
    return answer