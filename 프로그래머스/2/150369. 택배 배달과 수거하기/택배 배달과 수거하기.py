

def solution(cap, n, deliveries, pickups):

    answer = 0
    d_cap = 0  # 배달 가능한 여유분
    p_cap = 0  # 수거 가능한 여유분
    
    # 뒤에서부터(가장 먼 곳부터) 확인
    for i in range(n - 1, -1, -1):
        d_cap += deliveries[i]
        p_cap += pickups[i]
        
        # 해당 위치에 처리해야 할 배달이나 수거가 하나라도 남아있다면
        cnt = 0
        while d_cap > 0 or p_cap > 0:
            d_cap -= cap
            p_cap -= cap
            cnt += 1
            
        answer += (i + 1) * 2 * cnt
        
    return answer


    # greedy -> 가장 먼 목적지까지 가며 뒤에서부터 cap 만큼 처리
    answer = 0
    goal = n-1
    dtotal = sum(deliveries)
    ptotal = sum(pickups)
    
#    while dtotal >0 or ptotal>0:
    for i in range(goal, -1, -1) :
        if deliveries[i] != 0 or pickups[i] != 0 :
            goal = i
            #    break
        answer += (goal+1)*2
        dcap = cap
        pcap = cap

        if dtotal >0:
            dtotal -= dcap
            for i in range(goal, -1, -1) :
                if deliveries[i] == 0 : continue
                if deliveries[i] >= dcap :
                    deliveries[i] -= dcap
                    break
                else :    
                    dcap -= deliveries[i]
                    deliveries[i] = 0
        if ptotal >0:
            ptotal -= pcap
            for i in range(goal, -1, -1) :
                if pickups[i] == 0 : continue
                if pickups[i] >= pcap :
                    pickups[i] -= pcap
                    break
                else :
                    pcap -= pickups[i]
                    pickups[i] = 0
    
    return answer