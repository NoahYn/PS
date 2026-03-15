def solution(sizes):
    
    w_max = max([min(size) for size in sizes])
    h_max = max([max(size) for size in sizes])
    
    
    '''
    for size in sizes:
        if size[0] > size[1]:
            size.reverse()

    w_max = max([size[0] for size in sizes])
    h_max = max([size[1] for size in sizes])
    '''
    
    return w_max * h_max