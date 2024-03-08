select b.category, sum(bs.sales) total_sales
from book b
         join book_sales bs
              on b.book_id = bs.book_id
where year(sales_date) = 2022
  and month(sales_date) = '01'
group by category
order by category