-- 코드를 입력하세요
#USED_GOODS_BOARD와 USED_GOODS_USER 테이블에서 완료된 중고 거래의 총금액이 70만 원 이상인 사람


#회원 ID, 닉네임, 총거래금액을 조회


SELECT 
    U.USER_ID,
    U.NICKNAME,
    SUM(B.PRICE) as TOTAL_SALES 
    FROM USED_GOODS_USER as U
        JOIN USED_GOODS_BOARD as B on U.USER_ID = B.WRITER_ID 
    WHERE B.STATUS = 'DONE'
    GROUP BY U.USER_ID, U.NICKNAME
    HAVING SUM(B.PRICE) >= 700000
    
ORDER BY 3 asc