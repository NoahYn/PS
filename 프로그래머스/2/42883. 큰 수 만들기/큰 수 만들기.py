def solution(number, k):
    stack = [number[0]]
    
    for i in range(1,len(number)):
        while stack and k > 0 and stack[-1] < number[i] :
            stack.pop()
            k -= 1
            
        stack.append(number[i])

    
    return "".join(stack) if k == 0 else "".join(stack[:-k])