select p.category,  p.price max_price, p.product_name
from food_product p
         join (
    select max(price) price, category
    from food_product
    group by category
) pp
              on p.category = pp.category and p.price = pp.price
where p.category in ("과자","국","김치","식용유")
order by max_price desc