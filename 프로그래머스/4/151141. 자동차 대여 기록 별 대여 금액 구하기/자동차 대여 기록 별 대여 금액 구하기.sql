-- 코드를 입력하세요

with TRUCK_ID as (
    SELECT CAR_ID, DAILY_FEE FROM CAR_RENTAL_COMPANY_CAR 
    WHERE CAR_TYPE = '트럭'
),
CTE as (
SELECT H.HISTORY_ID,	
    (T.DAILY_FEE * (DATEDIFF(H.END_DATE, H.START_DATE) + 1)) as FEE, 
    (DATEDIFF(H.END_DATE, H.START_DATE) + 1) as DURATION
    
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY as H
    JOIN TRUCK_ID as T on T.CAR_ID = H.CAR_ID
)

SELECT HISTORY_ID, 

       TRUNCATE(FEE * 
            (1 - (
                    CASE
                        WHEN DURATION < 7 THEN 0
                        WHEN DURATION < 30 THEN
                            (SELECT DISCOUNT_RATE FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN 
    WHERE CAR_TYPE = '트럭' and DURATION_TYPE = '7일 이상')/100
                
                        WHEN DURATION < 90 THEN
                            (SELECT DISCOUNT_RATE FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN 
    WHERE CAR_TYPE = '트럭' and DURATION_TYPE = '30일 이상')/100
                        WHEN DURATION >= 90 THEN
                            (SELECT DISCOUNT_RATE FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN 
    WHERE CAR_TYPE = '트럭' and DURATION_TYPE = '90일 이상')/100
                    END
                    )
             )
       ,0) as FEE 

FROM CTE



#### TODO 할인율 추가 


ORDER BY 2 desc, 1 desc