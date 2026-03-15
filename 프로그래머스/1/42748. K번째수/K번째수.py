def solution(array, commands):
    answer = []
    for i,j,k in commands : 
        to_sort = array[i-1:j]
        to_sort.sort()
        print(to_sort)
        answer.append(to_sort[k-1])
    
    return answer