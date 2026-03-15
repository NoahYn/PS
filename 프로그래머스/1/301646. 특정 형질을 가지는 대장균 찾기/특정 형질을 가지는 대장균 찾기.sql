-- 코드를 작성해주세요

SELECT COUNT(*) as COUNT FROM ECOLI_DATA
WHERE not (GENOTYPE & 0b0010) # 2번 형질 
     and ((GENOTYPE & 0b0001) # 1번형질
     or (GENOTYPE & 0b0100)) # 3번