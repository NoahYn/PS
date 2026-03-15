-- 코드를 작성해주세요
# cnt
with recursive CTE as (
    SELECT ID, PARENT_ID, 1 as GENERATION from ECOLI_DATA 
        WHERE PARENT_ID is NULL
    UNION ALL
    SELECT C.ID, C.PARENT_ID, GENERATION+1 
    from CTE as P
         JOIN ECOLI_DATA as C on P.ID = C.PARENT_ID
)

SELECT COUNT(*) as COUNT, P.GENERATION
    from CTE as P 
        left join CTE as C on C.PARENT_ID = P.ID
    where
    C.PARENT_ID is null
    GROUP BY P.GENERATION

order by GENERATION asc