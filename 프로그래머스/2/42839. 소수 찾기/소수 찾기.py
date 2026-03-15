from itertools import permutations

def solution(numbers):
    def is_prime(num: int) -> bool:
        if num < 2 : return False
        if num == 2 : return True
        if num % 2 == 0 : return False
        for i in range(3, int(num**0.5) + 1, 2):
            if num % i == 0 : return False
        return True
    
    number_set = set()
    for length in range(1, len(numbers)+1):
        perm = permutations(numbers, length)
        for p in perm :
            number_set.add(int("".join(p)))

    answer = 0
    for n in number_set :
        if is_prime(n) : 
            answer += 1
    
    return answer

