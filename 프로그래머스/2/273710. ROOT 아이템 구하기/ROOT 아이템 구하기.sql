-- 코드를 작성해주세요

SELECT I.ITEM_ID,	I.ITEM_NAME FROM ITEM_INFO as I
    JOIN ITEM_TREE as T on I.ITEM_ID = T.ITEM_ID
    where T.PARENT_ITEM_ID is NULL
    order by I.ITEM_ID asc