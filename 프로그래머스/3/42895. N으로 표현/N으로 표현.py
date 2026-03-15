from itertools import combinations_with_replacement

def solution(N, number):
    if number == N : return 1

    DP = [set() for i in range(9)]
    DP[1].add(N)
    NN = N*10 + N
    DP[2] = {NN, N+N, N-N, N*N, N//N}
    if number in DP[2] : return 2
    
    NNN = NN*10 + N
    NNNN = NNN*10 + N
    NNNNN = NNNN*10 + N
    NNNNNN = NNNNN*10 + N
    NNNNNNN = NNNNNN*10 + N
    NNNNNNNN = NNNNNNN*10 + N
    DP[3].add(NNN)
    DP[4].add(NNNN)
    DP[5].add(NNNNN)
    DP[6].add(NNNNNN)
    DP[7].add(NNNNNNN)
    DP[8].add(NNNNNNNN)

    for i in range(3, 9) :
        for j in range(1, i//2+1) :
            j2 = i - j
            for x in DP[j] : 
                for y in DP[j2] :
                    DP[i].add(x+y)
                    DP[i].add(x-y)
                    DP[i].add(y-x)
                    DP[i].add(x*y)
                    if x != 0 :
                        DP[i].add(y//x)
                    if y != 0 :
                        DP[i].add(x//y)
        if number in DP[i] :
            return i
    return -1

