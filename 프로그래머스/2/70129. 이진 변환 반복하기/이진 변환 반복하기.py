def solution(s):
    num_transform = 0
    num_zero = 0
    while s != "1" :
        len_before = len(s)
        s = s.replace("0", "")   
        len_after = len(s)
        num_zero += (len_before - len_after)
        s = str(bin(len_after))[2:]
        num_transform += 1
    return [num_transform, num_zero]
