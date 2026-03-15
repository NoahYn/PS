from itertools import permutations

def solution(k, dungeons):
    # k : 피로도, 1~5000 int
    # dungeons : [(최소필요, 소모):1~1000] 1~8 
    
    permutation = permutations(dungeons)
    answer = 0
    num_d = len(dungeons)
    not_answer = num_d
    for p in permutation: 
        count = 0
        not_cnt = 0
        fatigue = k
        for least, consume in p:
            if fatigue >= least :
                fatigue -= consume
                count += 1
            else : 
                not_cnt += 1
                if not_cnt > not_answer :
                    continue
        answer = max(answer, count)
        not_answer = len(dungeons) - answer
        if answer >= len(dungeons) : 
            return answer
    return answer