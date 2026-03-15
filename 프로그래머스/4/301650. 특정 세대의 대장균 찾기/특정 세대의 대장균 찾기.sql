-- 코드를 작성해주세요

SELECT Third.ID FROM ECOLI_DATA as Third
    left join ECOLI_DATA as Second 
        on Third.PARENT_ID = Second.ID
        left join ECOLI_DATA as First
            on Second.PARENT_ID = First.ID
    where First.ID is not null and First.PARENT_ID is null 
    order by Third.ID