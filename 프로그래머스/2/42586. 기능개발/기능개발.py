def solution(progresses, speeds):
    num = len(progresses)
    days = []
    
    for i in range(num) :
        cnt = 0
        while progresses[i] < 100:
            progresses[i] += speeds[i]
            cnt += 1
        days.append(cnt)
    
    print(days)
    
    answer = []
    curr = 0
    maxday = days[0]
    for day in days :
        if maxday < day :
            maxday = day
            answer.append(curr)    
            curr = 0
        curr += 1
    
    if sum(answer) != num:
        answer.append(num-sum(answer))
        
    return answer