def solution(nums):
    answer = 0
    
    from itertools import combinations
    
    def is_prime(num: int) -> bool:
        for i in range(2, int(num**(1/2))+1):
            if num % i == 0:
                return False
        return True

    for comb in combinations(nums, 3):
        answer += is_prime(sum(comb))
    
    return answer