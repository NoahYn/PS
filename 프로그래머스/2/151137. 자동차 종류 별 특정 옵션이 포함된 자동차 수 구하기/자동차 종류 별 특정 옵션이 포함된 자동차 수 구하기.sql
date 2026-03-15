# -- 코드를 입력하세요 

WITH CTE AS (
    SELECT *, 1 as OPT FROM CAR_RENTAL_COMPANY_CAR
        WHERE OPTIONS like '%통풍시트%' or
              OPTIONS like '%열선시트%' or
              OPTIONS like '%가죽시트%' 
)


SELECT 
   CAR_TYPE	
   , COUNT(CAR_ID) as CARS 

FROM CAR_RENTAL_COMPANY_CAR 

WHERE CAR_ID in (SELECT CAR_ID FROM CTE)

GROUP BY CAR_TYPE

ORDER BY CAR_TYPE asc