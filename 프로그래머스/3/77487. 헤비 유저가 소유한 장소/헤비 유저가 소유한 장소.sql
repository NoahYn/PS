-- 코드를 입력하세요
/*
-> 등록한 공간의 정보를 
*/

with HEAVY as (
    SELECT HOST_ID, COUNT(*) FROM PLACES
    GROUP BY HOST_ID
    HAVING COUNT(*) >= 2
)
SELECT ID,
        NAME,
        HOST_ID
        
FROM PLACES

WHERE HOST_ID in (SELECT HOST_ID FROM HEAVY)
ORDER BY 1