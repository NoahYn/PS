from collections import defaultdict
from pprint import pprint

def solution(fees, records):
    time_map = defaultdict(list) 
    total_times = defaultdict(int)
    car_set = set()
    
    for r in records:
        time, car, state = r.split()
        hour, mins = map(int, time.split(':'))
        time = hour * 60 + mins
        car_set.add(car)
        
        if time_map[car] and time_map[car][-1][1] == 'IN':
            total_times[car] += (time - time_map[car][-1][0]) 
            time_map[car].pop()
        
        if state == 'IN' :
            time_map[car].append([time,state])
        
    for car, rest in time_map.items() :
        if rest :
            for r in rest :
                time, state = r
                total_times[car] += 23 * 60 + 59 - time
    
    car_set = sorted(list(car_set))
    
    answer = []
    for car in car_set :
        time = total_times[car]
        time -= fees[0]
        if time <= 0 :
            answer.append(fees[1])
        else :
            unit = time//fees[2]
            mod = time%fees[2]
            if mod > 0:
                unit += 1
            answer.append(fees[1] + unit * fees[3])             
    
    return answer