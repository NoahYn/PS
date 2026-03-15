def solution(spell, dic):
    spell.sort()
    for item in dic:
        if sorted(item) == spell:
            return 1
    return 2
