-- 코드를 입력하세요

with CTE as ( # 22년 8~10월에 총 대여횟수 5회 이상인 car_id 추출
    SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY 
        
#        WHERE START_DATE BETWEEN '2022-08-01' and '2022-10-31'
        WHERE DATE_FORMAT(START_DATE, '%Y-%m') in ('2022-08', '2022-09', '2022-10')

        GROUP BY CAR_ID
        HAVING COUNT(*) >= 5
)

SELECT 
    MONTH(START_DATE) as MONTH
    , CAR_ID
    , COUNT(*) as RECORDS
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY 
        
        WHERE CAR_ID in (SELECT CAR_ID FROM CTE)
            and YEAR(START_DATE) = 2022 and 
            MONTH(START_DATE) BETWEEN 8 and 10
        
        GROUP BY MONTH(START_DATE), CAR_ID
        ORDER BY 1 asc, 2 desc