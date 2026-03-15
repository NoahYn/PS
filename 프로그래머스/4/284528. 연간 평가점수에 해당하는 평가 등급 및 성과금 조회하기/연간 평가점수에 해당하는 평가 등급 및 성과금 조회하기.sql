-- 코드를 작성해주세요
with CTE as (
    SELECT 
        EMP_NO, 
        (
            CASE
                WHEN AVG(SCORE) >= 96 THEN 'S'
                WHEN AVG(SCORE) >= 90 THEN 'A'
                WHEN AVG(SCORE) >= 80 THEN 'B'
                ELSE 'C'
            END
        ) as GRADE, 
        (
            CASE
                WHEN AVG(SCORE) >= 96 THEN 0.20
                WHEN AVG(SCORE) >= 90 THEN 0.15
                WHEN AVG(SCORE) >= 80 THEN 0.10
                ELSE 0
            END
        ) as PER
    FROM HR_GRADE
    GROUP BY EMP_NO 
)

SELECT C.EMP_NO, E.EMP_NAME, C.GRADE,
    (E.SAL * C.PER) as BONUS 
    
FROM CTE as C 
    JOIN HR_EMPLOYEES as E on C.EMP_NO = E.EMP_NO