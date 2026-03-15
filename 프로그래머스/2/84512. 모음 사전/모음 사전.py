from itertools import product, combinations_with_replacement

def solution(word):
    product_list = list(product('AEIOU ', repeat=5))
    word_set = set(["".join(word).replace(" ", "") for word in product_list])
      
    index_dict = {word:i for i, word in enumerate(sorted(word_set))}
    
    return(index_dict[word])
    
