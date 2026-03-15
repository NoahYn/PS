def solution(brown, yellow):
    size = brown + yellow
    
    for h in range(3, int(size ** 0.5) + 1):
        if size % h == 0:
            w = size // h
            if (w-2) * (h-2) == yellow:
                return w, h
