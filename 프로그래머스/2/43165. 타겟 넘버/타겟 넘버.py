

def solution(numbers, target):        
    def search(i: int, result: int) :
        if i >= len(numbers):
            return int(result == target) # when current config is correct 

        return (search(i+1, result + numbers[i]) + # case for i'th index is positive
                search(i+1, result - numbers[i])) # case for i'th index is negative
    return (search(0, 0))