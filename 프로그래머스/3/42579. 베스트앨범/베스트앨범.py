from collections import defaultdict

def solution(genres, plays):
    answer = []
    genres_map = defaultdict(int)
    
    for genre, play in zip(genres, plays):
        genres_map[genre] += play
    
    sorted_genre = sorted(genres_map.items(), key = lambda x : x[1], reverse=True)
     
    for genre, _ in sorted_genre:
        first, second = -1, -1
        most, second_most = 0, 0
        genre_indices = [i for i in range(len(genres)) if genres[i] == genre]
        
        if len(genre_indices) == 1:
            answer.extend(genre_indices)
            continue
        
        for i in genre_indices : 
            if plays[i] > second_most :
                if plays[i] > most :
                    second_most = most
                    second = first
                    most = plays[i]
                    first = i
                else : 
                    second_most = plays[i]
                    second = i       
        
        answer.extend([first, second])
        
    
    return answer