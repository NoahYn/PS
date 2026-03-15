-- 코드를 입력하세요
with JF as (
    SELECT flavor, sum(total_order) as total_order from JULY
        group by flavor
),
FHF as (
    SELECT flavor, sum(total_order) as total_order from FIRST_HALF
        group by flavor
)

SELECT J.FLAVOR FROM JF as J JOIN FHF as F on J.flavor = F.flavor
    order by J.total_order + F.total_order desc limit 3