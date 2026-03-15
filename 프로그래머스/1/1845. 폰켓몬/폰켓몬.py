from collections import defaultdict
    
def solution(nums):
    n_type_dict = defaultdict(int)
    for n in nums:
        n_type_dict[n] += 1
    
    print(len(n_type_dict))
    return min(len(n_type_dict), len(nums)/2)