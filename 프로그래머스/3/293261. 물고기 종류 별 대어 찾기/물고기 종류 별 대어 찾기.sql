-- 코드를 작성해주세요

SELECT ID, FISH_NAME, LENGTH from (
    SELECT I.ID, N.FISH_NAME, I.LENGTH,
        RANK() over (partition by I.FISH_TYPE order by I.LENGTH desc) as rnk
        FROM FISH_INFO as I
            INNER JOIN FISH_NAME_INFO as N on I.FISH_TYPE = N.FISH_TYPE
) as SUB
    where rnk = 1
ORDER BY ID ASC

# 다른 풀이 
# SELECT I.ID, N.FISH_NAME, I.LENGTH
#     FROM FISH_INFO as I
#         INNER JOIN FISH_NAME_INFO as N on I.FISH_TYPE = N.FISH_TYPE
#     WHERE (I.LENGTH, I.FISH_TYPE) in (
#         SELECT MAX(LENGTH), FISH_TYPE FROM FISH_INFO 
#         GROUP BY FISH_TYPE
#     )
# ORDER BY ID ASC


    
# 다중 열 서브쿼리
# 인라인 뷰는 무조건 alias 필요!