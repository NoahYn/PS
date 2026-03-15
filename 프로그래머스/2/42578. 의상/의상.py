from collections import Counter

def solution(clothes):
    counts = Counter([cloth[1] for cloth in clothes])
    values = counts.values()
    result = 1
    for value in values:
        result *= (value + 1)
    
    return result - 1
    