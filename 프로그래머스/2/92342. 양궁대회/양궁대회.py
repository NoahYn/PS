from functools import cmp_to_key

def solution(n, info):
    if n == 1 :
        return [-1]

    cands = [] # 점수 차이, return할 정수 배열
    def mycmp(x, y) :
        if x[0] == y[0] :
            for i in range(10, -1, -1) :
                if x[1][i] != y[1][i] :
                    return y[1][i] - x[1][i]
        else : 
            return y[0] - x[0]
    
    score = 0
    for i in range(11) :
        if info[i] :
            score -= (10 - i)
    
    to_win = [x+1 for x in info]
    def dfs(i, score, cand) :  
        if sum(cand) == n : # 전부 쏜 경우
            if score > 0: 
                cands.append([score, cand]) # 이기는 경우만 추가
        elif i == 10 :
            if score > 0: # 이길 수 있는 건 다 쏘고 화살이 남은 경우
                num_rest = n - sum(cand)
                cand[10] += num_rest
                cands.append([score, cand[:]])
        else : 
            if n-sum(cand) >= to_win[i] : # 남은 화살로 i번째 점수를 얻을 수 있는 경우
                cand[i] += to_win[i]
                if to_win[i] == 1 : # 어피치가 안쏜 점수
                    score += (10-i)
                    dfs(i+1, score, cand[:])
                    score -= (10-i)
                else : # 어피치 점수를 뺏는 경우
                    score += (10-i) * 2
                    dfs(i+1, score, cand[:])
                    score -= (10-i) * 2
                cand[i] -= to_win[i]
            dfs(i+1, score, cand[:]) # 안쏘고 다음 점수로
    dfs(0, score, [0 for _ in range(11)])
    if cands :
        return sorted(cands, key=cmp_to_key(mycmp))[0][1]
    return [-1]