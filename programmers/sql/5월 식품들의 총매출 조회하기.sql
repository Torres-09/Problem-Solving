select fp.product_id, fp.product_name, sum(fp.price * fo.amount) total_sales
from food_product fp
         join food_order fo
              on fp.product_id = fo.product_id
where fo.produce_date like "2022-05%"
group by product_id
order by total_sales desc, fp.product_id