-- 코드를 입력하세요

with CTE as (
    SELECT BOARD_ID FROM USED_GOODS_BOARD
    ORDER BY VIEWS desc
    limit 1 
)
--    조회수가 가장 높은 중고거래 게시물

SELECT 
    CONCAT('/home/grep/src/', BOARD_ID, '/', FILE_ID, FILE_NAME, FILE_EXT) as FILE_PATH

FROM USED_GOODS_FILE 

WHERE BOARD_ID = (SELECT * FROM CTE)

ORDER BY FILE_ID desc