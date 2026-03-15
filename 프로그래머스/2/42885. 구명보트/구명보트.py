from collections import deque

def solution(people, limit):
    answer = 0
    people = deque(sorted(people))
    print(people)
    while people :
        mx = people.pop()
        answer += 1
        if people and mx + people[0] <= limit :
            people.popleft()
    
    return answer