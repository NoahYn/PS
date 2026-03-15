def solution(n, t, m, timetable):
    # calculate last bustime
    # calculate each crew and bus using Q
    
    start = 9 * 60
    buses = [9 * 60 + t * i for i in range(n)]
    crews = sorted([60 * int(x[:2]) + int(x[3:]) for x in timetable])

    i = 0
    cnt = 0
    for crew in crews : # 크루들 도착 순서대로
        while crew > buses[i] : # 버스시간 뒤에 온 경우 -> 다음 버스 탐
            i += 1
            cnt = 0
            if i == len(buses) : 
                break
        if i == len(buses) : 
            break
        if time <= buses[i] : # 버스시간 전에 온 경우
            cnt += 1
            if cnt == m : # 버스 수용인원 초과 -> 다음 버스
                i += 1
                cnt = 0
                if i == len(buses) : # 마지막 버스 마지막 사람. 이 사람 앞에 타야 함!
                    time -= 1
                    hours, minutes = str(time // 60), str(time % 60)

                    while len(hours) < 2 :
                        hours = "0"+hours
                    while len(minutes) < 2 :
                        minutes = "0"+minutes
                    return hours + ":" + minutes   

    # 마지막 버스 안놓침. 마지막 버스 시간에 타면 ok
    hours, minutes = str(buses[-1] // 60), str(buses[-1] % 60)
    while len(hours) < 2 :
        hours = "0"+hours
    while len(minutes) < 2 :
        minutes = "0"+minutes
    return hours + ":" + minutes

# 좀 더 깔끔한 코드(gemini)
from collections import deque

def solution(n, t, m, timetable):
    # 1. 시간 변환 및 정렬
    crew_times = sorted([int(f[:2]) * 60 + int(f[3:]) for f in timetable])
    crew_queue = deque(crew_times)
    
    # 2. 버스 시간표 생성
    bus_times = [9 * 60 + i * t for i in range(n)]
    
    last_crew_time = 0
    
    for bus in bus_times:
        cnt = 0 # 해당 버스에 탄 인원
        while crew_queue and crew_queue[0] <= bus and cnt < m:
            last_crew_time = crew_queue.popleft() # 마지막으로 탄 크루의 시간 기록
            cnt += 1
            
        # 3. 마지막 버스인 경우 정답 결정
        if bus == bus_times[-1]:
            # 자리가 남았다면 -> 버스 도착 시간에 딱 맞춰 온다
            if cnt < m:
                answer_time = bus
            # 자리가 없다면 -> 마지막으로 탄 크루보다 1분 빨리 온다
            else:
                answer_time = last_crew_time - 1
                
    # 4. HH:MM 포맷으로 변환 (f-string 활용)
    return f"{answer_time // 60:02}:{answer_time % 60:02}"