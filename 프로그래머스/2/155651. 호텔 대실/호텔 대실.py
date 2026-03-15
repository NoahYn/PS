def solution(book_time):
    times = []
    for t_in, t_out in book_time :
        h, m = map(int, t_in.split(":"))
        times.append([h*60+m,0])
        h, m = map(int, t_out.split(":"))
        times.append([h*60+m+10,1])
    times.sort(key=lambda x : (x[0],-x[1]))
    stack = []
    answer = 0
    curr = 0
    for t, state in times :
        if state == 0:
            curr += 1
            answer = max(answer, curr)
        else :
            curr -= 1
    
    return answer