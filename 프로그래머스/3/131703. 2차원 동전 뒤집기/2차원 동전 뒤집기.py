from pprint import pprint


def solution(beginning, target):
    num_row = len(beginning)
    num_col = len(beginning[0])
    
    def flip_row(r, table) :
        for c in range(num_col) :
            table[r][c] = (table[r][c] + 1) % 2
    
    def flip_col(c, table) :
        for r in range(num_row) :
            table[r][c] = (table[r][c] + 1) % 2
    
    xor = []
    for r in range(num_row) :
        xor_row = []
        for c in range(num_col) :
            xor_row.append(beginning[r][c] ^ target[r][c])
        xor.append(xor_row)
        
    print(xor)
    cnt, cnt2 = 0, 0
    for i, col in enumerate(xor[0]) : 
        if col == 1 :
            cnt += 1
            flip_col(i, xor)
        else :
            cnt2 += 1
            continue

    for row in xor :
        if all(row) :
            cnt += 1
        elif not any(row) :
            cnt2 += 1
        else :
            return -1

    return min(cnt, cnt2)