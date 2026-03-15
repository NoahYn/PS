from pprint import pprint
from collections import defaultdict
import heapq

## set은 hash를 사용하므로 작은 원소들은 정렬된 것처럼 보여도, 원소가 커지면 아님!!

def solution(food_times, k):
    # food_times[i] = i번째 음식 소요시간
    # 다 먹었으면 return -1
    # len(food_times) ~2000 -> 2십만 O(nlogn)
        # food_times는 정렬 가능 !
    # each food_time ~ 1000 -> 1억 O(log n)
    # k ~ 2백만 -> at most O(nlogn) -> 1조? O(log n)
    if sum(food_times) <= k : return -1

    cntmap = defaultdict(int)
    for food in food_times : # 20만
        cntmap[food] += 1

    num_food = len(food_times)
    cntset = sorted(cntmap.keys())
    prev = 0
    for nxt in cntset :
        diff = nxt - prev
        spend = num_food * diff
        
        if k < spend: 
            break
        k -= spend
        num_food -= cntmap[nxt]
        prev = nxt
            
    k %= num_food
    
    for i, food in enumerate(food_times) : # 20만
        if food < nxt : continue
        else : 
            if k == 0 :
                return i+1
            k -= 1
        
    return -1