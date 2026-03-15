def solution(s):
    stack = []
    for c in s :
        if c == ")":
            if not stack :
                return False
            stack.pop()
        else :
            stack.append(c)
    
    return len(stack) == 0
    