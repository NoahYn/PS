## s[a:b] == s[a:b][::-1]

def solution(s):
    if s == s[::-1] : return len(s)

    def possible(ln) :
        for i in range(len(s) - (ln-1)) :
            if s[i:i+ln] == s[i:i+ln][::-1] :
                return True
        return False
    
    left = 1
    right = len(s) - 1
    
    while left < right :
        mid = right - (right - left)//2
        if possible(mid) : 
            left = mid
        elif possible(mid+1) :
            left = mid+1
        else : 
            right = mid -1
    
    return left
