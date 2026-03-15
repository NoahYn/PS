from collections import defaultdict
from pprint import pprint

def solution(record):
    # 1~ 10만 -> 최대 O(N log N)
    umap = defaultdict(str) # uid : nickname
    for r in record :
        if r[0] == 'C' or r[0] == 'E' :        
            status, uid, nickname = r.split()
            umap[uid] = nickname
 
    answer = []
    for r in record:
        if r[0] == 'L' :
            status, uid = r.split()        
            answer.append(f"{umap[uid]}님이 나갔습니다.")
        elif r[0] == 'E' :        
            status, uid, nickname = r.split()
            answer.append(f"{umap[uid]}님이 들어왔습니다.")

    return answer