def solution(s):
    answer = ''
    for i, c in enumerate(s) :
        if i == 0 : 
            if c.isalpha() :
                answer += c.upper()
            else :
                answer += c
        else :
            if c.isalpha() :
                if s[i-1] == ' ' :
                    answer += c.upper()
                else : 
                    answer += c.lower()
            else : 
                answer += c
                
    return answer