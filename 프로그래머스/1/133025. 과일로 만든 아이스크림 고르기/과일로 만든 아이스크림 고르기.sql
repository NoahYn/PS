-- 코드를 입력하세요
SELECT F.FLAVOR from first_half as F inner join icecream_info as I on F.flavor = I.flavor where F.total_order > 3000 and I.ingredient_type = 'fruit_based' order by F.total_order desc