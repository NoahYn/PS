from collections import defaultdict
import sys
sys.setrecursionlimit(10000000)

def solution(k, room_number):
    answer = []
    avail = defaultdict(int)
    def find_empty_room(idx) :
        if avail[idx] == 0 :
            avail[idx] = idx + 1
            return idx
        
        avail[idx] = find_empty_room(avail[idx])
        return avail[idx]

    for x in room_number :
        answer.append(find_empty_room(x))
    return answer

'''
def solution(k, room_number):
    avail = defaultdict(int)
    
    answer = []
    num_customer = len(room_number)
    for i in range(num_customer) :
        head = room_number[i]        
        curr = head
        path = []
        while avail[curr] != 0:
            curr = avail[curr]
            path.append(curr)
        answer.append(curr)

        tail = curr + 1
        avail[curr] = tail

        avail[head] = tail
        for p in path : 
            avail[p] = tail
            
    return answer
'''