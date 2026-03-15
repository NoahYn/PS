from collections import deque

def can_move(x, y) :
    count = 0
    for i in range(len(x)):
        if x[i] == y[i] : 
            count += 1
            
    return (count == len(x)-1)

def solution(begin, target, words):
    words.append(begin)
    Q = deque()
    steps = {word:0 for word in words}
    
    Q.append(begin)
    steps[begin] = 1
    
    if not target in words : return 0
    
    while Q:
        curr = Q.popleft()
        
        for word in words : 
            if steps[word] > 0 : continue # already computed
            if not can_move(curr, word) : continue # two words are not related
            steps[word] = steps[curr] + 1
            Q.append(word)

    return steps[target] -1