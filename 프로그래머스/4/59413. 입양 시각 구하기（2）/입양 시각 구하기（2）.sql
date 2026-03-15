-- 코드를 입력하세요

with recursive CTE as (
    SELECT 0 as HOUR, 0 as COUNT
    
    UNION ALL
    SELECT HOUR+1, 0 FROM CTE
        WHERE HOUR < 23
),
CTE2 as (
    SELECT 
        HOUR(DATETIME) as HOUR, 
        COUNT(*) as COUNT
        FROM ANIMAL_OUTS
        GROUP BY HOUR(DATETIME)
        UNION ALL 
        SELECT * FROM CTE
)
    
SELECT HOUR, SUM(COUNT) as COUNT FROM CTE2
    GROUP BY HOUR
ORDER BY 1 asc