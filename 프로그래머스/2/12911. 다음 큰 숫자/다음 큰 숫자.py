def solution(n):
    num1 = str(bin(n)).count('1')
    while True :
        n += 1
        num2 = str(bin(n)).count('1')
        if num1 == num2:
            return n