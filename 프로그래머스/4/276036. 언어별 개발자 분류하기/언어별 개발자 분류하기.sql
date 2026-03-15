-- 코드를 작성해주세요

SELECT * FROM (

SELECT 
    (
        CASE 
            WHEN ((SKILL_CODE & (SELECT SUM(CODE) FROM SKILLCODES
                    WHERE CATEGORY = 'Front End')) and # Front End skill
                (SKILL_CODE & (SELECT CODE FROM SKILLCODES
                            WHERE NAME='Python'))) # Python skill
                THEN 'A' 
            WHEN SKILL_CODE & (SELECT CODE FROM SKILLCODES
                            WHERE NAME = 'C#')
                THEN 'B'
            WHEN SKILL_CODE & (SELECT SUM(CODE) FROM SKILLCODES
                    WHERE CATEGORY = 'Front End')
                THEN 'C'
            ELSE NULL
        END          
    ) as GRADE,
    ID, EMAIL FROM DEVELOPERS
) as SUB
WHERE GRADE is not null   
    
ORDER BY 1 asc, 2 asc