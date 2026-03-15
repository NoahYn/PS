import heapq
from collections import deque

def solution(jobs):
    # i th job (s, l)
    # l, s, i 순으로 수행
    # pQ엔 s순으로 push  
    num_jobs = len(jobs)
    temp = []
    for i, (s, l) in enumerate(jobs) :
        temp.append([s, l, i])
    
    temp.sort()
    jobs = deque(temp[:])

    pQ = []
    answer = 0

    t = 0
    while jobs or pQ: 
        while jobs and jobs[0][0] <= t :
            s, l, i = jobs.popleft()
            heapq.heappush(pQ, (l, s, i))
        
        if pQ : # 수행할 태스크가 있는 경우
            todo = heapq.heappop(pQ)
            t += todo[0]
            answer += (t-todo[1])            
        else : # 없는 경우 다음 태스크 시간으로 점프
            t = jobs[0][0]

    return answer // num_jobs





'''
import heapq

def solution(jobs):
    # 소요시간 l 짧음 -> 요청시각 s 빠름 -> 번호 i 작음
    heap = []
    for i, (s, l) in enumerate(jobs):
        heapq.heappimport heapq
from collections import deque

def solution(jobs):
    # i th job (s, l)
    # l, s, i 순으로 수행
    # pQ엔 s순으로 push  
    num_jobs = len(jobs)
    temp = []
    for i, (s, l) in enumerate(jobs) :
        temp.append([s, l, i])
    
    temp.sort()
    jobs = deque(temp[:])

    pQ = []
    answer = 0

    t = 0
    dt = 1
    while jobs or pQ: 
        while jobs and jobs[0][0] <= t :
            s, l, i = jobs.popleft()
            heapq.heappush(pQ, (l, s, i))
        
        if pQ :
            todo = heapq.heappop(pQ)
            dt = todo[0]
            answer += (t+dt-todo[1])
        
        t += dt
        dt = 1
        
    return answer // num_jobs



ush(heap, (l,s,i))
    
    time = 0
    invalid = []
    answer = 0
    while heap or invalid :
        if heap :
            pop = heapq.heappop(heap)
        else : # 힙이 비었으므로 처리할 작업 x -> 요청시각까지 이동
            pop = heapq.heappop(invalid)
            pop = (pop[1],pop[0],pop[2])
            time = pop[1] 
        if pop[1] > time : # 요청시각 > 현재time
            heapq.heappush(invalid, (pop[1],pop[0],pop[2])) # 요청시각이 빠른 걸 꺼낼 수 있도록
            continue
        else :
            time += pop[0] # 소요시간 
            answer += time - pop[1] # 현재 시간 - 요청시각 = 반환시간
            while invalid : 
                p = invalid.pop()
                heapq.heappush(heap, (p[1],p[0],p[2]))
                
    return answer // len(jobs)
'''