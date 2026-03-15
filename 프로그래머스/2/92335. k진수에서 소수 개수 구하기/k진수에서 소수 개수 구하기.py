def solution(n, k):
    def is_prime(x) :
        if x == '' : return False
        x = int(x)
        if x < 2 : return False
        if x == 2 : return True
        if x % 2 == 0 : return False
        for i in range(3, int(x**(1/2)) +1, 2) :
            if x % i == 0 : 
                return False
        return True
    
    k_nary = []
    temp = n
    while temp > 0 :
        k_nary.append(str(temp % k))
        temp //= k
    k_nary.reverse()
    k_nary = "".join(k_nary)
    
    candidates = k_nary.split('0')
    
    answer = 0

    for c in candidates : 
        if is_prime(c) :
            answer += 1
    
    return answer