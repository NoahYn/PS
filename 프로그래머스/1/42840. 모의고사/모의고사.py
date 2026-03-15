from itertools import cycle

def solution(answers):
    
    no_1 = cycle([1,2,3,4,5])
    no_2 = cycle([2,1,2,3,2,4,2,5])
    no_3 = cycle([3,3,1,1,2,2,4,4,5,5])
    
    points = [0] * 3
    
    for n1, n2, n3, answer in zip(no_1, no_2, no_3, answers):
        if n1 == answer : 
            points[0] += 1
        if n2 == answer : 
            points[1] += 1
        if n3 == answer : 
            points[2] += 1

    max_point = max(points)
    return [i+1 for i, p in enumerate(points) if p == max_point]    
     
