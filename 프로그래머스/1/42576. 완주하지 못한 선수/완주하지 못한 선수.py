def solution(participant, completion):
    from collections import defaultdict    

    compl_dict = defaultdict(int)
    for c in completion:
        compl_dict[c] += 1
    
    for p in participant:
        if compl_dict[p] < 1:
            return p
        compl_dict[p] -= 1
    return ''