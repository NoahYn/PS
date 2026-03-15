from math import perm, comb

def solution(n):
    if n < 4 : return n

    answer = 0
    num1 = n
    num2 = 0
    while num1 >= 0 :
        answer += comb(num1+num2, num1) % 1234567
        
        num1 -= 2
        num2 += 1

    return answer % 1234567