def solution(citations):
    citations.sort(reverse=True)
    answer = 0
    for i,c in enumerate(citations) :
        if i+1 <= c :
            answer += 1
        else :
            break
    return answer