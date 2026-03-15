## real greedy

def solution(routes):
    routes.sort(key = lambda x : x[1])
    answer = 0
    idx_tv = -30001
    
    for car_in, car_out in routes : 
        if idx_tv < car_in : 
            idx_tv = car_out
            answer += 1
    
    return answer