-- 코드를 입력하세

SELECT  A.APNT_NO,	
        P.PT_NAME,	
        P.PT_NO,	
        D.MCDP_CD, 
        D.DR_NAME,	
        A.APNT_YMD

FROM APPOINTMENT as A 
    JOIN PATIENT as P on P.PT_NO = A.PT_NO
    JOIN DOCTOR as D on D.DR_ID = A.MDDR_ID
        
WHERE A.APNT_YMD like '2022-04-13%'
    and A.APNT_CNCL_YN = 'N'
    and A.MCDP_CD = 'CS'

ORDER BY 6 asc