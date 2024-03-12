select distinct a.user_id, a.product_id
from online_sale a
         join online_sale b
              on a.user_id = b.user_id and a.product_id = b.product_id
where a.sales_date != b.sales_date
order by a.user_id, a.product_id desc;

SELECT user_id, product_id
from online_sale as o
group by user_id, product_id
having count(online_sale_id) >= 2
order by o.user_id, o.product_id desc;