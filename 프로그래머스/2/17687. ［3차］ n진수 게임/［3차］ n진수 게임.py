def solution(n, t, m, p):
    answer = ''
    i = 0

    dic = '0123456789ABCDEF'

    def to_nary(x) :
        if x == 0 : 
            return '0'
        result = ''
        while x > 0 :
            mod = x % n
            result += dic[mod]    

            x //= n
        return result[::-1]

    total = t * m + p
    while total > 0 :
        nxt = to_nary(i)
        answer += nxt
        i += 1
        total -= 1

    return answer[p-1:m*t:m]