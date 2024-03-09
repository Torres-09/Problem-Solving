select p.product_code, sum(p.price * o.sales_amount) sales
from product p
         join offline_sale o
              on p.product_id = o.product_id
group by product_code
order by sales desc, product_code