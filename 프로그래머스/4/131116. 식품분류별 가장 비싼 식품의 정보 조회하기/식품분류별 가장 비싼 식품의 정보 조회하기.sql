-- 코드를 입력하세요
WITH CTE as (
    SELECT CATEGORY, 
            MAX(PRICE) as MAX_PRICE     
    FROM FOOD_PRODUCT
    WHERE CATEGORY in ('과자', '국', '김치', '식용유')
    GROUP BY CATEGORY
)

SELECT C.CATEGORY, C.MAX_PRICE, F.PRODUCT_NAME FROM CTE as C 
        JOIN FOOD_PRODUCT as F on C.CATEGORY = F.CATEGORY
        WHERE C.MAX_PRICE = F.PRICE
        ORDER BY C.MAX_PRICE DESC

    
    # 식용유	8950	맛있는마조유
    # 김치	19000	맛있는배추김치
    # 국	2900	맛있는김치찌개
    # 과자	1950	맛있는허니버터칩